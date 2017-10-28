

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

        //object creation
        void createSong(string songTitle,string songComposer, int sID);
        void createRecording(string t, string a,string p, int y, int aID);
        void creatUser(string id, string name);
        void createTrack(int sID, int aID, int trackNum);
        void addTrackToPlaylist(int songID,string userID, string plName);
        void addPlaylistToUser(string userID,string plName,int plID);

        //object deletion
        void removeRecording(int albumID);
        void removeTrackFromPlaylists(int songID);
        void removeTrackFromTrack(int songID);
        void removeTrack(int songID);
        void removeSongFromSongs(int songID);
        void removeSong(int songID);
        void removeUserFromUsers(string userID);
        void removePlaylistFromUsers(string userID, string plName);
        void removeTrackFromPlaylistByName(string userID, string plName, int songID);

        //getters
        map<int, Recording*>* getRecordings();
        vector<User *>* getUsers();
        map<int, Song *>* getSongs();
        map<int, Track*>* getTracks();

        //Show methods
        void showSongs();
        void showTracks();
        void showRecordingsWithTracks();
        void showRecordingsWithoutTracks();
        void showUsers();
        void showUserPlaylists();

private:
        map<int,Recording*> recordings;
        vector<User*> users;
        map<int,Song*> songs;
        map<int,Track*> tracks;

};


#endif //TESSERACT_TEST_DATABASE_H
