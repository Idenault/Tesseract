OBJ = main.o mytunes.o UI.o command.o str_util.o Song.o Track.o Recording.o Playlist.o User.o Database.o

mytunes: $(OBJ)
	g++ -o mytunes $(OBJ)

main.o:	main.cpp 
	g++ -c main.cpp

mytunes.o:	mytunes.cpp mytunes.h UI.h
	g++ -c mytunes.cpp

UI.o:	UI.cpp UI.h 
	g++ -c -std=c++11 UI.cpp
	
command.o:	command.cpp command.h 
	g++ -c -std=c++11 command.cpp

str_util.o:	str_util.cpp str_util.h 
	g++ -c -std=c++11 str_util.cpp

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
