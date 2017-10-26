#include "Database.h"


Database::Database();

void Database::createSong(const string &songTitle, const string &songComposer, int sID)
{
    songs[sID]=*new Song(songTitle,songComposer,sID);
}

void Database::createTrack(int sID, int aID, int trackNum)
{
    if(songs.find(sID)!=end())


}
