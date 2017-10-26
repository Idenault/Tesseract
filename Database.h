

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

private:
        map<string,Recording> recordings; //stores the recordings in a map sorted by album id for quick backwards serching
        vector<User> users; // users are stored in a vector because we will need to iterate throug users and playlists
        map<string,Song> songs; // songs are sotored in a map sorted by there unique song id
        map<string,vector<Track>> tracks; // tracks are stored in a map sorted by song id but because there can be duplicate tracks we store the tracks in a vector inside the map


};


#endif //TESSERACT_TEST_DATABASE_H
