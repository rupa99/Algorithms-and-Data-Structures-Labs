#include <iostream>
#include <vector>
using namespace std;
    
class playlist {

private: 
	vector <string> playlist_obj; 

public: 
playlist();
~playlist();

void initialize_song(string song_artist); 
void play_song(int song_number);
void erase_song(int song_number); 

bool match_checker(string song_artist); 
void printnewvector();

};