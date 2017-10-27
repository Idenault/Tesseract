
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

