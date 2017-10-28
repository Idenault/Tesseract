
#include <string>
#include <iostream>
#include <vector>
#include "Playlist.h"
#include "User.h"

User::User(const string id, const string name) {
    cout << "BUILDING A USER!!!!"<<endl;
    userID = id;
    userName = name;
}

User::User(User &copy) {
    cout << "Copy of User made.";
}

User::~User() {
    cout << "DESTROYING A USER!!!!"<<endl;
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

string User::toString()const
{
    return "User ID: " + userID + " User Name: " + userName + " NUMBER OF PLAYLISTS: " + to_string(playlists.capacity());
}

void User::removePlaylist(string pLname)
{
    for (int i = 0; i < playlists.size() ; ++i)
    {
        if(pLname == playlists[i]->getName())
        {
            delete(playlists[i]);
            playlists.erase(playlists.begin()+i);
        }

    }

}

ostream& operator<<(ostream& out, const User& userObject)
{
    out<<userObject.toString()<<endl;
    return out;
}