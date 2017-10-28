#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#include "str_util.h"
#include "command.h"



Command::Command(string cmdStr){
	Database db = *new Database;
	commandString = cmdStr;
	parseAndEditDB(commandString);
}

string Command::getCommandString(){return commandString;}
string Command::getCommandName(){return tokens[0];}
string Command::getToken(int i){
	   if(i >= 0 && i<tokens.size())
	      return tokens[i];
	   else
		  return "";
   
}

bool Command::isCommand(string aCommandName){
	return getCommandName().compare(aCommandName) == 0;
}

bool Command::isUICommand(){
	for(int i=0; i<NumberOfUICommands; i++)
		if(getCommandName().compare(UICommands[i]) == 0) return true;
	return false;
}
bool Command::isAppCommand(){
		for(int i=0; i<NumberOfAppCommands; i++)
		if(getCommandName().compare(AppCommands[i]) == 0) return true;
	return false;
}
bool Command::isDevCommand(){
		for(int i=0; i<NumberOfDevCommands; i++)
		if(getCommandName().compare(DevCommands[i]) == 0) return true;
	return false;
}
void Command::parseAndEditDB(string cmdStr) {
	/*
	Parse (tokenize) the command 
	
	Parse a command like:
	add -s "The Girl From Ipanema"
	into:
	add
	-s
	The Girl From Ipanema
	*/
	string buffer;
	stringstream ss(cmdStr); // Insert the string into a stringstream

	//Tokenize the command
	//collect substrings between "" quotation marks as a single token
	//and strip off the "" quotation marks.
	//This parser essentially does a trim() as well because it
	//uses a stringstream that strips off white space

	string tokenStr = ""; //for collecting "" quoted substring words
	bool collecting = false; //not collecting quoted words
	while (ss >> buffer) {
		if ((buffer.length() == 2) &&
			(buffer[0] == '"') && (buffer[1] == '"')) {
			//word is a "" empty string
		} else if ((buffer.length() > 2) &&
				   (buffer[0] == '"') &&
				   (buffer[buffer.length() - 1] == '"')) {
			//single word in "" quotes -strip off the quotes
			tokens.push_back(buffer.substr(1, buffer.length() - 2));
		} else if ((buffer.length() == 1) && (buffer[0] == '"')) {
			//word is a single "
			//could be the starting quote or ending quote
			if (collecting == false) {
				collecting = true; //start collecting
			} else {
				collecting = false; //stop collecting
				tokens.push_back(StrUtil::trim(tokenStr));
				tokenStr = "";
			}
		} else if ((buffer.length() > 1) && (buffer[buffer.length() - 1] == '"')) {
			//word ends with "
			tokenStr.append(" " + buffer.substr(0, buffer.length() - 1));
			collecting = false;
			tokens.push_back(StrUtil::trim(tokenStr));
			tokenStr = "";
		} else if ((buffer.length() > 1) && (buffer[0] == '"')) {
			//word starts with "
			tokenStr.append(buffer.substr(1, buffer.length() - 1));
			collecting = true;
		} else if (collecting == true)
			//word within "" quoted substring
			tokenStr.append(" " + buffer);
		else
			tokens.push_back(buffer);
	}

	if (tokens.size() == 0) tokens.push_back("NO COMMAND");

	//Command is now tokenized into tokens vector




	//TOKENS VECTOR YO! 2EZ thanks Lou!

	//shows use of (cheesing) iterator
	for (vector<string>::iterator it = tokens.begin(); it != tokens.end(); ++it) {

		//if adding something
		if (*it == CMD_ADD) {
			it++;

			// if thing being added is a song to DB
			if (*it == "-s" && tokens.size() == 5) {

				int songID = stoi(*++it);
				string title = *++it;
				string composer = *++it;

				db.createSong(title, composer, songID);

				cout << "Adding Song: " << songID << " " << title << " " << composer << " to database.\n";
				break;
			}


			//if thing being added is a recording
			else if(*it == "-r" && tokens.size() == 7){

				int albumID = stoi(*++it);
				string title = *++it;
				string artist = *++it;
				string producer = *++it;
				int year = stoi(*++it);

				db.createRecording(title, artist, producer, year, albumID);

				cout << "Adding Recording: " << albumID << " " << title << " " << artist << " " << producer << " " << year << " to database.\n";
				break;
			}


			//if thing being added is a track
			else if(*it == "-t" && tokens.size() == 6){

				int albumID = stoi(*++it);
				int songID = stoi(*++it);
				int trackNum = stoi(*++it);

				db.createTrack(songID, albumID, trackNum);

				cout << "Adding Track: " << songID << " " << trackNum << " to recording " << " " << albumID << "\n";
				break;
			}


			//if thing being added is a user
			else if(*it == "-u" && tokens.size() == 4){

				string userID = *++it;
				string userName = *++it;

				db.creatUser(userID, userName);

				cout << "Adding User: " << userID << " " << userName << " to database.\n";
				break;
			}


			//if thing being added is a playlist
			else if (*it == "-p" && tokens.size() == 5){

				string userID = *++it;
				string playlistName = *++it;
				int playlistID = stoi(*++it);

				db.addPlaylistToUser(userID, playlistName, playlistID);

				cout << "Adding Playlist: " << playlistName << " " << playlistID << " to User: " << userID <<"\n";
				break;
			}

			//if thing being added is a track to a playlist
			else if (*it == "-l" && tokens.size() == 5){

				string userID = *++it;
				string playlistName = *++it;
				int songID = stoi(*++it);

				db.addTrackToPlaylist(songID, userID, playlistName);

				cout << "Adding Song: " << songID << " " << " to User: " << userID << " Playlist: " << playlistName << "\n";
				break;
			}
			else {
				cout << "Unrecognized add command. Type .help for examples of proper syntax.\n";
				break;
			}
		}

		//if removing something
		if(*it == CMD_DELETE){
			it++;

			//if thing being removed is a song
			if(*it == "-s" && tokens.size() == 3){
				int songID = stoi(*++it);

				db.removeSong(songID);

				cout << "Removing Song: " << songID << "\n";
				break;

			}

			//if thing being removed is a recording
			else if (*it == "-r" && tokens.size() == 3){
				int albumID = stoi(*++it);

				db.removeRecording(albumID);

				cout << "Removing Recording: " << albumID << "\n";
				break;

			}

			//if thing being removed is a track from a recording
			else if (*it == "-t" && tokens.size() == 4){
				////////////////////////////////////////////////////////////////////////////////////////////////////////////

			}

			//if thing being removed is user
			else if (*it == "-u" && tokens.size() == 3){
				string userID = *++it;

				db.removeUserFromUsers(userID);

				cout << "Removing User: " << userID << "\n";
				break;
			}

			//if thing being removed is a playlist
			else if (*it == "-p" && tokens.size() == 4){
				string playlistName = *++it;
				string userID = *++it;

				db.removePlaylistFromUsers(userID, playlistName);

				cout << "Removing Playlist: " << playlistName << " from User: " << userID << "\n";
				break;
			}

			//if thing being removed is a track from a playlist
			else if (*it == "-l" && tokens.size() == 5){
				int songID = stoi(*++it);
				string playlistName = *++it;
				string userID = *++it;

				db.removeTrackFromPlaylistByName(userID, playlistName, songID);

				cout << "Removing Track: " << songID << " from User: " << userID << " from Playlist: " << playlistName << "\n";
				break;
			}

			//else print "you're dumb"
			else{
				cout << "Unrecognized delete command. Type .help for examples of proper syntax.";
				break;
			}

		}


		//if showing something
		if(*it == CMD_SHOW){
			it++;

			//if thing being shown is all songs
			

			//if thing being show is all users

			//if thing being shown is all playlist

			//if thing being shown is all tracks in a playlist

			//if thing being shown is all recordings

			//if thing being shown is all tracks
		}
	}
}
