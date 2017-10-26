

#ifndef TESSERACT_TEST_DATABASE_H
#define TESSERACT_TEST_DATABASE_H

#include <string>
#include <vector>
#include <map>
#include "Recording.h"
#include "User.h"
#include "Song.h"
#include "Track.h"

using namespace std;

class Database
{
    public:
        Database();
        void createSong(const string &songTitle, const string &songComposer, int sID);
        void createRecording(const string t, const string a, const string p, int y, int aID);
        void creatUser(const string id, const string name, vector<vector<Track*>> pLists);
        void createTrack(int sID, int aID, int trackNum);
        void removeRecording(int albumID);

private:
        map<int,Recording> recordings; //stores the recordings in a map sorted by album id for quick backwards serching
        vector<User> users; // users are stored in a vector because we will need to iterate throug users and playlists
        map<int,Song> songs; // songs are sotored in a map sorted by there unique song id
        map<int,vector<Track>> tracks; // tracks are stored in a map sorted by song id but because there can be duplicate tracks we store the tracks in a vector inside the map
};


#endif //TESSERACT_TEST_DATABASE_H
