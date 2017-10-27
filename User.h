#ifndef TESSERACT_TEST_USER_H
#define TESSERACT_TEST_USER_H


#include <string>
#include <vector>
#include "Track.h"
#include "Playlist.h"

using namespace std;

class User
{
public:

    User(string id, string name, vector<Playlist> pLists);
    ~User();
    User(User& copy);
    string getUserID();
    string getName();
    vector<Playlist> getPlaylists();
    void addPlaylist(string pLname, int pLID);
    void removePlaylist(string pLname);
    void removePlaylist(int pLID);


private:

    string userID;
    string userName;
    vector<Playlist> playlists;

};


#endif //TESSERACT_TEST_USER_H
