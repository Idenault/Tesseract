
#include "Playlist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Playlist::Playlist(string playlistName, int playlistID) {
    name = playlistName;
    id = playlistID;
}

Playlist::~Playlist() {
    cout << "Destroying Playlist. Name: " << name << " ID: " << id;
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

/*
void Playlist::removeTrackFromPlaylist(Track track) {
    for (int i=0; i < tracksInPlaylist.size(); i++){
        if (tracksInPlaylist[i] == &track){
            tracksInPlaylist.erase(tracksInPlaylist.begin()+i);
        }
    }
}*/

string Playlist::toString() {
    cout << "Displaying playlist: " << name << " ID: " << id << "\n";
    for (int i=0; i < tracksInPlaylist.size(); i++){
        cout <<"SONG: "<<(tracksInPlaylist[i])->toString() << "\n";
    }
}
