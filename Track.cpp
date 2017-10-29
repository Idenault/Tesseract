#include <iostream>
#include "Track.h"


Track::Track(int sID, int aID, int trackNum, Song* const tPointer)
{
    cout << "BUILDING A TRACK!!!!"<<endl;
    songID = sID;
    albumID = aID;
    trackNumber =  trackNum;
    trackPointer = tPointer;
}

Track::Track(Track &copy) {
    cout << "this Should not happen"<<endl;
}

Track::~Track()
{
    cout<<"DESTROYING A TRACK!!!!"<<endl;
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
    return trackPointer->toString() + " TRACK: " + to_string(trackNumber);
}

ostream& operator<<(ostream& out, const Track& trackObject)
{
    out<<trackObject.toString()<<endl;
    return out;
}
