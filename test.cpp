#include "Song.h"
#include "Track.h"
#include "User.h"
#include "Database.h"
#include <iostream>


using namespace std;
int main()
{
    string songName  = "The Brown Eyed Brown Eye";
    string bandName = "The Browns";
    string userName = "ShitHead123";
    string userID = "001";
    string playlistname = "fucking music";
    int playlistId = 1;
    int sID = 69;
    int albumID = 1;
    Database dB;

    dB.createSong(songName,bandName,sID);

    //cout<<*dB.getSongs()->at(sID);
    dB.showSongs();
    dB.createTrack(sID,albumID,1);
    //cout<<*dB.getTracks()->at(sID);
    dB.createRecording(songName,bandName,userName,1000,albumID);
    //cout<<*dB.getRecordings()->at(albumID);
    dB.creatUser(userID,userName);
    //cout<<*dB.getUsers()->at(0);
    dB.addPlaylistToUser(userID,playlistname,playlistId);
    dB.addTrackToPlaylist(sID,userID,playlistname);
    //cout<<*dB.getUsers()->at(0)->getPlaylists().at(0);
    dB.removePlaylistFromUsers(userID,playlistname);
    dB.removeUserFromUsers(userID);
    dB.removeRecording(albumID);
    dB.removeTrackFromTrack(sID);
    dB.removeSongFromSongs(sID);



}
