
#ifndef TESSERACT_TEST_TRACK_H
#define TESSERACT_TEST_TRACK_H


#include "Song.h"

class Track
{
public:


    Track(int sID, int aID, int trackNum,  Song* const tPointer);
    ~Track();
    Track(Track &copy);
    int getSongID() const;
    int getAlbumID() const;
    const Song* getTrackPointer() const;
    string toString() const;

private:
    int songID;
    int albumID;
    int trackNumber;
    Song* trackPointer;

};

ostream& operator<<(ostream& out, const Track& trackObject);

#endif //TESSERACT_TEST_TRACK_H
