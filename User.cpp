
#include <string>
#include <iostream>
#include <vector>
#include "Playlist.h"
#include "User.h"

User::User(const string id, const string name) {
    userID = id;
    userName = name;
}

User::User(User &copy) {
    cout << "Copy of User made.";
}

User::~User() {
    cout << "User object destroyed.";
}

string User::getUserID() {
    return userID;
}

string User::getName() {
    return userName;
}

vector<Playlist*> User::getPlaylists() {
    return playlists;
}

void User::addPlaylist(const string pLName, int pLID) {
    Playlist* temp = new Playlist(pLName, pLID);
    playlists.push_back(temp);
}

/*
void User::removePlaylist(int pLID) {
    for (int i=0; i < playlists.size(); i ++){
        if (pLID == playlists[i].getID()){
            playlists.erase(playlists.begin()+i);
        }
    }
}

void User::removePlaylist(string pLname) {
    for (int i=0; i < playlists.size();i++){
        if (pLname == playlists[i].getName()){
            playlists.erase(playlists.begin()+i);
        }
    }
}
*/
