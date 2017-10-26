#include "Database.h"


Database::Database();

void Database::createSong(const string &songTitle, const string &songComposer, int sID)
{
    songs[sID]=*new Song(songTitle,songComposer,sID);
}

void Database::createTrack(int sID, int aID, int trackNum)
{
    if(songs.find(sID) != songs.end())
    {

        tracks[sID].push_back(*new Track(sID,aID,trackNum,&songs[sID]));
    }
}
 void Database::createRecording(const string t, const string a, const string p, int y, int aID)
 {
     recordings[aID]= *new Recording(t,a,p,y,aID);
 }

void Database::  creatUser(const string id, const string name, vector<vector<Track*>> pLists)
{
    users.push_back(*new User(id,name,pLists));
}

void Database::removeRecording(int albumID)
{
    recordings.erase(recordings.find(albumID));
}