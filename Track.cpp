#include <iostream>
#include "Track.h"


Track::Track(int sID, int aID, int trackNum,  Song* const tPointer)
{
    songID = sID;
    albumID = aID;
    trackNumber =  trackNum;
    trackPointer = tPointer;
}

Track::Track(Track &copy) {

}

int Track::getSongID() const {
    return songID;
}

int Track::getAlbumID() const {
    return albumID;
}

const Song* Track::getTrackPointer() const{
    return trackPointer;
}

string Track::toString() const{
    return trackPointer->toString() + " track: " + to_string(trackNumber);
}

