#include <iostream>
#include "Recording.h"

Recording::Recording(const string t, const string a, const string p, int y, int aID)
{
    cout << "BUILDING A RECORDING!!!!"<<endl;
    title =t;
    artist =a;
    producer = p;
    year = y;
    albumID = aID;
}

Recording::Recording(Recording &copy){cout << "this Should not happen"<<endl;}

Recording::~Recording()
{
    cout << "DESTROYING A RECORDING!!!!"<<endl;
}

string Recording::toString() const
{
    return "ALBUM TITLE: " + formater.toTitleCase(title) + " ARTIST: " + formater.toTitleCase(artist) + " PRODUCER: " + producer + " YEAR: " + to_string(year) + " ID: " + to_string(albumID);
}

string Recording::toStringWithTracks() const
{
    string returnStr = "ALBUM TITLE: " + formater.toTitleCase(title) + " ARTIST: " + formater.toTitleCase(artist) + " PRODUCER: " + producer + " YEAR: " + to_string(year) + " ID: " + to_string(albumID) +"\n";
    returnStr += "TRACKS: ";
    returnStr += "\n";

    if(!tracks.empty())
    {
        for(auto& t: tracks)
        {
            returnStr += t->toString();
        }
    }
    else{returnStr += "this Recording is Empty";}

    return returnStr;
}

int Recording::getAlbumID() const{
    return albumID;
}

vector<Track*> Recording::getTracks() {
    return tracks;
}
void Recording::addTrack(Track* trackPointer){
    tracks.push_back(trackPointer);
}

ostream& operator<<(ostream& out, const Recording& recordingObject)
{
    out<<recordingObject.toString()<<endl;
}
