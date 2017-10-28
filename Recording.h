

#ifndef TESSERACT_TEST_RECORDING_H
#define TESSERACT_TEST_RECORDING_H

#include <string>
#include "str_util.h"

using namespace std;

class Recording
{

public:

    Recording(const string t, const string a, const string p, int y, int aID);
    Recording(Recording& copy);
    ~Recording();
    int getAlbumID()const;
    string toString()const;

private:

    string title;
    string artist;
    string producer;
    int year;
    int albumID;
    StrUtil formater;
};
ostream& operator<<(ostream& out, const Recording& recordingObject);

#endif //TESSERACT_TEST_RECORDING_H
