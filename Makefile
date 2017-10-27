OBJ = test.o Song.o Track.o Recording.o Playlist.o User.o Database.o

mytunes: $(OBJ)
	g++ -o mytunes $(OBJ)

test.o:	test.cpp
	g++ -c test.cpp

Song.o: Song.cpp Song.h
	g++ -c -std=c++11 Song.cpp

Track.o: Track.cpp Track.h
	g++ -c -std=c++11 Track.cpp

Recording.o: Recording.cpp Recording.h
	g++ -c -std=c++11 Recording.cpp

Playlist.o: Playlist.cpp Playlist.h
	g++ -c -std=c++11 Playlist.cpp

User.o: User.cpp User.h
	g++ -c -std=c++11 User.cpp

Database.o: Database.cpp Database.h
	g++ -c -std=c++11 Database.cpp

clean:
	rm -f $(OBJ) mytunes
