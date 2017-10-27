#include "Song.h"
#include "Track.h"
#include "User.h"
#include "Database.h"
#include <iostream>


using namespace std;
int main()
{
    string songName  = "Brown Eyed Brown Eye";
    string bandName = "The Browns";
    string userName = "ShitHead123";
    string userID = "001";
    string playlistname = "fucking music";
    int playlistId = 1;
    int sID = 69;
    int albumID = 1;
    Database dB;

    dB.createSong(songName,bandName,sID);
    dB.createTrack(sID,albumID,1);
    dB.createRecording(songName,bandName,userName,1000,albumID);
    dB.creatUser(userName,userID);
    cout<<dB.getRecordings()->operator[](1)->getAlbumID();
    dB.removeRecording(albumID);
    dB.removeTrackFromTrack(sID);



}
