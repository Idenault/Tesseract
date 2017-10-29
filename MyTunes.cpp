
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
#include "mytunes.h"


MyTunes::MyTunes():view(this)
{
	db = Database();
}

void MyTunes::run()
{
	//start user interface

	view.run(); 

}
void MyTunes::executeCommand(Command cmd){

	vector<string> tokens = cmd.getTokens();

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

				it++;
				int albumID = stoi(*++it);
				int songID = stoi(*++it);
				int trackNum = stoi(*++it);

				db.createTrack(songID, albumID, trackNum);
				db.addTrackToRecording(albumID, songID);

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
				cout << "Unrecognized add command. Type .help for examples of proper syntax." << endl;
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

				cout << "Removing Song: " << songID << endl;
				break;

			}

				//if thing being removed is a recording
			else if (*it == "-r" && tokens.size() == 3){
				int albumID = stoi(*++it);

				db.removeRecording(albumID);

				cout << "Removing Recording: " << albumID << endl;
				break;

			}

				//if thing being removed is a track from a recording
			else if (*it == "-t" && tokens.size() == 4){
				int songID = stoi(*++it);
				int albumID = stoi(*++it);

				db.removeTrackFromRecording(albumID, songID);

				cout << "Removing track/song: " << songID << " from Recording: " << albumID << endl;
				break;

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
				cout << "Unrecognized delete command. Type .help for examples of proper syntax." << endl;
				break;
			}

		}


		//if showing something
		if(*it == CMD_SHOW){
			it++;

			//if thing being shown is all songs
			if (*it == "songs" && tokens.size() == 2){
				cout << "trying to show songs" << endl;
				db.showSongs();
				break;
			}

				//if thing being show is all users
			else if (*it == "users" && tokens.size() == 2){
				db.showUsers();
				break;
			}

				//if thing being shown is all playlist belonging to a user
			else if (*it == "playlists" && tokens.size() == 3){
				string userID = *++it;
				db.showUserPlaylists(userID);
				break;
			}

				//if thing being shown is all tracks in a playlist
			else if (*it == "songs" && tokens.size() == 4){
				string userID = *++it;
				string playlistName = *++it;

				db.showSongsInPlaylist(userID, playlistName);
				break;
			}

				//if thing being shown is all recordings
			else if (*it == "recordings" && tokens.size() == 2){
				db.showRecordingsWithoutTracks();
				break;
			}

				//if thing being shown is all tracks
			else if (*it == "tracks" && tokens.size() == 2){
				db.showTracks();
				break;
			}

			else{
				cout << "Unrecognized show command. Type .help for examples of proper syntax." << endl;
			}
		}
	}
}







