

#ifndef TESSERACT_TEST_RECORDING_H
#define TESSERACT_TEST_RECORDING_H

#include <string>

using namespace std;

class Recording
{

public:

    Recording(const string &title, const string &artist, const string &producer, int year, int albumID);
    ~Recording();
    Recording(Recording& copy);
    int getAlbumID();

private:

    string title;
    string artist;
    string producer;
    int year;
    int albumID;
};


#endif //TESSERACT_TEST_RECORDING_H
