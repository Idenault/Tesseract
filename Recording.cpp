#include "Recording.h"

Recording::Recording(const string t, const string a, const string p, int y, int aID)
{
    title =t;
    artist =a;
    producer = p;
    year = y;
    albumID = aID;
}

Recording::Recording(Recording &copy){}

int Recording::getAlbumID() const{
    return albumID;
}