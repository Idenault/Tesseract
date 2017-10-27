

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
        void createSong(string songTitle,string songComposer, int sID);
        void createRecording(string t, string a,string p, int y, int aID);
        void creatUser(string id, string name);
        void createTrack(int sID, int aID, int trackNum);
        void removeRecording(int albumID);
        void removeTrackFromPlaylists(int songID);
        void removeTrackFromTrack(int songID);
        void removeTrack(int songID);
        map<int, Recording*>* getRecordings();
        vector<User *>* getUsers();
        map<int, Song *>* getSongs();
        map<int, vector<Track *>>* getTracks();

private:
        map<int,Recording*> recordings;
        vector<User*> users;
        map<int,Song*> songs;
        map<int,vector<Track*>> tracks;

};


#endif //TESSERACT_TEST_DATABASE_H
