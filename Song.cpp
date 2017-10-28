#include <iostream>
#include "Song.h"
#include "str_util.h"


using namespace std;

Song::Song(const string songTitle, const string songComposer, const int sID)
{
    cout << "BUILDING A SONG!!!"<<endl;
    titel = songTitle;
    composer = songComposer;
    id = sID;

}

Song::~Song()
{
    cout<<"DESTROYING A SONG!!!!"<<endl;
}

Song::Song(Song &copy)
{
    cout << "this Should not happen";
}

int Song::getsongID() const {
    return id;
}

string Song::toString()const
{
    return "SONG ID: " + to_string(id)+ " SONG NAME: " + formater.toTitleCase(titel) + " COMPOSER: " + formater.toTitleCase(composer);
}

ostream& operator<<(ostream& out, const Song& songObject)
{
    out<<songObject.toString()<<endl;
    return out;
}