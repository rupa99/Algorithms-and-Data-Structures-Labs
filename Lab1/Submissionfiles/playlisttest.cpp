#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "playlist.h"

using namespace std;

int main() {

  string line = "";
  string word = "";
  playlist p1;

  while (getline(cin, line)) {
    stringstream singleline(line);
    getline(singleline, word, ' ');

    /*CASE1: If the input is i*/
    if (word == "i") {
      string init("");

      while (singleline >> word) {
        string add(word);
        init.append(" ");
        init.append(add);
      }
      p1.initialize_song(init);

    } 
    /*CASE2: If the input is p*/
    else if (word == "p") {
      int play_index;
      while (singleline >> word) {
        play_index = stoi(word);

      }
      p1.play_song(play_index);

    } 

    /*CASE3: If the input is e*/
    else if (word == "e") {
      int erase_index;
      while (singleline >> word) {
        erase_index = stoi(word);
      }
      p1.erase_song(erase_index);
    }

  }
}