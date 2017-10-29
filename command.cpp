
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

#include "str_util.h"
#include "command.h"


Command::Command(string cmdStr){
	commandString = cmdStr;
	parseAndEditDB();
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

vector<string> Command::getTokens() {
	return tokens;
}
void Command::parseAndEditDB() {


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
	stringstream ss(commandString); // Insert the string into a stringstream

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

}
