
#ifndef TESSERACT_PLAYLIST_H
#define TESSERACT_PLAYLIST_H

#include <string>
#include <vector>
#include "Track.h"


using namespace std;

class Playlist {

public:
    Playlist(string playlistName, int playlistID);
    ~Playlist();
    Playlist(Playlist& copy);
    int getID();
    string getName();
    vector<Track*> getTracksInPlaylist();
    void addTrackToPlaylist(Track* track);
    void removeTrackFromPlaylist(Track track);
    string toString();

private:
    string name;
    int id;
    vector<Track*> tracksInPlaylist;
};
ostream& operator<<(ostream& out, Playlist& pLObject);

#endif //TESSERACT_PLAYLIST_H
