#include <iostream>
#include "Database.h"

Database::Database()
{

}

void Database::createSong(const string songTitle, const string songComposer, int sID)
{
    songs[sID]=new Song(songTitle,songComposer,sID);
}

void Database::createTrack(int sID, int aID, int trackNum)
{
    if(songs.find(sID) != songs.end())
    {
        tracks[sID].push_back(new Track(sID,aID,trackNum,songs[sID]));
    }
}
 void Database::createRecording(const string t, const string a, const string p, int y, int aID)
 {
     recordings[aID]= new Recording(t,a,p,y,aID);
 }

void Database::creatUser(const string id, const string name)
{
    users.push_back(new User(id,name));
}

void Database::removeRecording(int albumID)
{
    if(recordings.find(albumID)!= recordings.end())
    {
        delete(recordings[albumID]);
        recordings.erase(recordings.find(albumID));
    }
}

void Database::removeTrackFromTrack(int songID)
{
    if(tracks.find(songID)!= tracks.end())
    {
        Track* temp = tracks[songID][0];
        for (int i = 0; i <tracks[songID].size() ; ++i)
        {
            tracks.erase(tracks.find(songID));
        }
        delete(temp);
    }
    else {//do nothing
    }
}

void Database::removeTrackFromPlaylists(int songID)
{
    for (int i = 0; i <users.size() ; ++i)
    {
        for (int j = 0; j <users[i]->getPlaylists().size() ; ++j)
        {
            for (int k = 0; k <users[i]->getPlaylists()[j]->getTracksInPlaylist().size() ; ++k)
            {
                if (users[i]->getPlaylists()[j]->getTracksInPlaylist()[k]->getSongID()==songID)
                {
                    users[i]->getPlaylists()[j]->getTracksInPlaylist().erase(users[i]->getPlaylists()[j]->getTracksInPlaylist().begin()+k);
                }

            }
        }

    }

}

void Database::removeTrack(int songID)
{
    removeTrackFromTrack(songID);
    removeTrackFromPlaylists(songID);
}

void Database::removeSongFromSongs(int songID)
{
    if(songs.find(songID)!=songs.end())
    {
        delete(songs[songID]);
        songs.erase(songs.find(songID));
    }

}

void Database::removeSong(int songID)
{
    removeSongFromSongs(songID);
    removeTrack(songID);
}


// generically uninteresting  Getter methods

map<int, Recording *>* Database::getRecordings(){
    return &recordings;
}

vector<User *>* Database::getUsers(){
    return &users;
}

map<int, Song *>* Database::getSongs(){
    return &songs;
}

map<int, vector<Track *>>* Database::getTracks(){
    return &tracks;
}










