#include <iostream>
#include "Database.h"

Database::Database()
{

}


// add and create methods
void Database::createSong(const string songTitle, const string songComposer, int sID)
{
    songs[sID]=new Song(songTitle,songComposer,sID);
}
void Database::createTrack(int sID, int aID, int trackNum)
{
    if(songs.find(sID) != songs.end())
    {
        tracks[sID] = new Track(sID,aID,trackNum,songs[sID]);
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
void Database::addTrackToPlaylist(int songID, string userID, const string plName)
{
    if(tracks.find(songID) != tracks.end())
    {
        for (int i = 0; i <users.size(); ++i)
        {
            if(users[i]->getUserID() == userID)
            {
                for (int j = 0; j <users[i]->getPlaylists().size() ; ++j)
                {
                    if(users[i]->getPlaylists()[j]->getName() == plName)
                    {
                        users[i]->getPlaylists()[j]->addTrackToPlaylist(tracks[songID]); // need to reevalaute this cause we need to be able to serch tracks by track id
                    }
                    else if(j==users[i]->getPlaylists().size()-1); //invalid playlist

                }
            }
            else if(i==users.size()-1); //invalid user
        }
    }
    else; // invalid track


}
void Database::addPlaylistToUser(const string userID, const string plName, int plID)
{

    for (int i = 0; i <users.size(); ++i)
    {
        if(users[i]->getUserID() == userID)
        {
            users[i]->getPlaylists().push_back(new Playlist(plName,plID));
        }
        else if(i==users.size()-1); //invalid user
    }

}


// remove and destruction methods
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
        delete(tracks[songID]);
        tracks.erase(tracks.find(songID));
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
void Database::removeUserFromUsers(const string userID)
{
    for (int i = 0; i <users.size(); ++i)
    {
        if(users[i]->getUserID() == userID)
        {
            delete(users[i]);
            users.erase(users.begin()+i);
        }
    }
}
void Database::removePlaylistFromUsers(const string userID, const string plName)
{
    for (int i = 0; i <users.size(); ++i)
    {
        if(users[i]->getUserID() == userID)
        {
            for (int j = 0; j <users[i]->getPlaylists().size() ; ++j)
            {
                if(users[i]->getPlaylists()[j]->getName() == plName)
                {
                    delete(users[i]->getPlaylists()[j]);
                    users[i]->getPlaylists().erase( users[i]->getPlaylists().begin()+j);
                }

            }
        }
    }

}
void Database::removeTrackFromPlaylistByName(const string userID, const string plName, int songID)
{
    for (int i = 0; i <users.size() ; ++i)
    {
        for (int j = 0; j <users[i]->getPlaylists().size() ; ++j)
        {
           if(users[i]->getPlaylists()[j]->getName()==plName)
           {
               for (int k = 0; k <users[i]->getPlaylists()[j]->getTracksInPlaylist().size() ; ++k)
               {
                   if(users[i]->getPlaylists()[j]->getTracksInPlaylist()[k]->getSongID() == songID)
                   {
                       users[i]->getPlaylists()[j]->getTracksInPlaylist().erase(users[i]->getPlaylists()[j]->getTracksInPlaylist().begin()+k);
                   }
               }
           }
        }

    }

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
map<int,Track *>* Database::getTracks(){
    return &tracks;
}










