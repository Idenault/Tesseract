
#include <string>
#include <iostream>
#include <vector>
#include "Playlist.h"
#include "User.h"

User::User(string id, string name, vector<Playlist> pLists) {
    userID = id;
    userName = name;
    playlists = pLists;
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

vector<Playlist> User::getPlaylists() {
    return playlists;
}

void User::addPlaylist(string pLName, int pLID) {
    Playlist* temp = new Playlist(pLName, pLID);
    playlists.push_back(*temp);
    cout << "I have no idea what this will print. An address maybe? if it prints an object, then fuck yeah! ... i think. I don't know, maybe this works: " << temp->toString();
}

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
