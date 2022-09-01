# List all the drivers
all: playlisttest


playlisttest: playlisttest.cpp
	g++ -std=c++11 -o  playlisttest playlisttest.cpp playlist.cpp playlist.h


# List all the executables under 'all:'
clean:
	rm *.o playlisttest

