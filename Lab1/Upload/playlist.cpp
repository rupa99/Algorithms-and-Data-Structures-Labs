#include <iostream>
#include<cmath>
#include <array>
#include <iterator>
#include<cstdlib>
#include <vector>
#include<string.h>
using namespace std;
#include "playlist.h"

//default constructor
playlist::playlist() {

}

/*destructor- used to clear off the 
dynamically created vector*/
playlist::~playlist() {
  playlist_obj.clear();
}

/*adding a new song_artist 
to the vector*/
void playlist::initialize_song(string song_artist) {

  if (playlist_obj.empty()) {
    playlist_obj.push_back(song_artist);
    cout << "success" << endl;

  } else {
    bool is_match = match_checker(song_artist);

    if (is_match) {
      cout << "can not insert" << song_artist << endl;
    } else {
      playlist_obj.push_back(song_artist);
      cout << "success" << endl;
    }

  }
}

/*playing the song from the vector if the song exists, 
else- execture error conditions*/
void playlist::play_song(int song_number) {
  if (playlist_obj.empty()) {
    cout << "could not play " << song_number << endl;
  } else if (song_number <= 0) {
    cout << "could not play " << song_number << endl;
  } else if (song_number > (playlist_obj.size())) {
    cout << "could not play " << song_number << endl;
  } else {
    for (int i = 0; i < playlist_obj.size(); i++) {
      if (song_number == (i + 1)) {
        cout << "played " << song_number << playlist_obj[i] << endl;
        break;
      }
    }

  }

}

/*erasing the song from the vector if the song exists, 
else- execture error conditions*/
void playlist::erase_song(int song_number) {
  if (playlist_obj.empty()) {
    cout << "could not erase " << song_number << endl;
  } else if (song_number <= 0) {
    cout << "could not erase " << song_number << endl;
  } else if (song_number > (playlist_obj.size())) {
    cout << "could not erase " << song_number << endl;
  } else {
    for (int i = 0; i < playlist_obj.size(); i++) {
      if (song_number == (i + 1)) {
        playlist_obj.erase(playlist_obj.begin() + i);
        cout << "success" << endl;
        break;
      }
    }

  }

}

/*itterating through the playlist and checking if the
song exists in the vector, if it exists return 
true, else return false
*/
bool playlist::match_checker(string song_artist) {
  for (auto x: playlist_obj) {
    if (x == song_artist) {
      return true;
    }
  }
  return false;
}

/*used to print the vector- for testing purrposes
*/
void playlist::printnewvector() {
  for (auto x: playlist_obj) {
    cout << x << endl;
  }

}