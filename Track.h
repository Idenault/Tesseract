
#ifndef TESSERACT_TEST_TRACK_H
#define TESSERACT_TEST_TRACK_H


#include "Song.h"

class Track
{
public:


    Track(int songID, int albumID, int trackNumber, const Song &trackPointer);
    ~Track(void);
    Track(Track &copy);
    int getSongID() const;
    int getAlbumID() const;
    int getTrackNumber() const;
    const Song &getTrackPointer() const;

private:
    int songID;
    int albumID;
    int trackNumber;
    Song trackPointer;

};


#endif //TESSERACT_TEST_TRACK_H
