#include "Song.h"
#include <string>
#include <iostream>

using namespace std;
int main()
{
    string ass = "Brown Eyed Brown Eye";
    string ass2 = "The Browns";
    int ass3 = 69;

    Song* brown = new Song(ass,ass2,ass3);

    delete(brown);

}
