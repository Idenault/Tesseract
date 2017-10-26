#include "Song.h"
#include "Track.h"
#include <iostream>

using namespace std;
int main()
{
    string ass = "Brown Eyed Brown Eye";
    string ass2 = "The Browns";
    int ass3 = 69;

    Song* brown = new Song(ass,ass2,ass3);
    Track* shit = new Track(1,1,1,brown);

    cout<< brown->toString()<<endl;
    cout<< shit->toString()<<endl;
    delete(shit);
    delete(brown);

}
