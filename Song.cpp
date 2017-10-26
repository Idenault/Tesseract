#include <iostream>
#include "Song.h"

using namespace std;

Song::Song(const string songTitle, const string songComposer, const int sID)
{
    cout << "BUILDING!!!"<<endl;
    titel = songTitle;
    composer = songComposer;
    id = sID;

}

Song::Song(Song &copy)
{
    cout << "error will robinson ERROR!!!!!! (you need to pass by refrence or pointer)";
}

int Song::getsongID() const {
    return id;
}

string Song::toString()const
{
    return to_string(id)+ " " + titel + " " + composer;
}


