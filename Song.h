

#ifndef TESSERACT_TEST_SONG_H
#define TESSERACT_TEST_SONG_H

#include<string>

using namespace std;


class Song
{

public:

    Song(const string &songTitle, const string  &composer, const int &sID);
    ~Song(void);
    Song(Song& copy);
    int getsongID();
    string toString();

private:

    string titel;
    string composer;
    int id;

};


#endif //TESSERACT_TEST_SONG_H
