

#ifndef TESSERACT_TEST_USER_H
#define TESSERACT_TEST_USER_H


#include <string>
#include <vector>
#include "Song.h"

using namespace std;

class User
{
public:



    User(const string id, const string name, vector<vector<Song*>> pLists, vector<string> pLNames);
    ~User(void);
    User(User& copy);
    string &getUserID();
    string &getName();
    vector<vector<Song>> &getPlaylists();
    vector<string> &getPlaylistNames();

private:

    string userID;
    string name;
    vector<vector<Song>> playlists;
    vector<string> playlistNames;

};


#endif //TESSERACT_TEST_USER_H
