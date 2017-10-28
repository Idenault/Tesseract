
#include "Playlist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Playlist::Playlist(string playlistName, int playlistID) {
    cout << "BUILDING A PLAYLIST!!!!"<<endl;
    name = playlistName;
    id = playlistID;
}

Playlist::~Playlist() {
    cout << "DESTROYING A PLAYLIST!!!!"<<endl;
}
Playlist::Playlist(Playlist &copy) {
    cout << "Copy constructor made.";
}

string Playlist::getName() {
    return name;
}

int Playlist::getID() {
    return id;
}

vector<Track*> Playlist::getTracksInPlaylist(){
    return tracksInPlaylist;
}

void Playlist::addTrackToPlaylist(Track* track) {
    tracksInPlaylist.push_back(track);
}

string Playlist::toString() {
    string returnStr = "Displaying playlist: " + name + " ID: "  + to_string(id)+ "\n";

    if(tracksInPlaylist.size()>0)
    {
        for (int i=0; i < tracksInPlaylist.size(); i++)
        {
            returnStr += tracksInPlaylist[i]->toString() + "\n";
        }
    }
    else{
        returnStr += "This Is an Empty Playlist";
    }
    return returnStr;
}

ostream& operator<<(ostream& out, Playlist& pLObject)
{
    out<<pLObject.toString()<<endl;
    return out;
}