

#ifndef TESSERACT_TEST_SONG_H
#define TESSERACT_TEST_SONG_H

#include<string>
#include "str_util.h"

using namespace std;


class Song
{

public:

    Song(string songTitle, string  composer,int sID);
    Song(Song& copy);
    ~Song();
    int getsongID()const;
    string toString()const;

private:

    string titel;
    string composer;
    int id;
    StrUtil formater;

};

ostream & operator<<(ostream& out, const Song& aSong);

#endif //TESSERACT_TEST_SONG_H
