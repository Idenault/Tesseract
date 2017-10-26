

#ifndef TESSERACT_TEST_SONG_H
#define TESSERACT_TEST_SONG_H

#include<string>

using namespace std;


class Song
{

public:

    Song(string songTitle, string  composer,int sID);
    Song(Song& copy);
    int getsongID()const;
    string toString()const;

private:

    string titel;
    string composer;
    int id;

};

#endif //TESSERACT_TEST_SONG_H
