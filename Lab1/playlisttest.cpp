#include <iostream>
#include <sstream>
#include <bits/stdc++.h> 


#include "playlist.h"

using namespace std; 

int main(){

	string line = ""; 
	string word = ""; 
  playlist p1;
  

	while(getline(cin, line)){

	stringstream singleline(line);

	getline(singleline, word, ' ');



    if(word == "i"){
 		string init(""); 

    	//cout<<"I'm in i "<<endl; 
    	while(singleline >> word){
       		string add(word);
       		init.append(" ");
       		init.append(add);
    	}
    	//cout <<"the word in i is = "<<init<<endl;
      p1.initialize_song(init);

    }

    else if (word == "p" ){
      int play_index; 
    	//cout<<"I'm in p "<<endl; 
    	while(singleline >> word) {
        play_index = stoi(word);
       
    	}
  
      //cout<<"index playing = "<<play_index<<endl; 
      p1.play_song(play_index);

    }

    else if (word == "e"){
    	//cout<<"I'm in e "<<endl;
      int erase_index; 
    	while(singleline >> word) {
          erase_index = stoi(word); 
       		//cout <<"the number in e is = "<<erase_index<<endl; 
    	}
    	//cout<<"index erasing = "<<erase_index<<endl; 
      p1.erase_song(erase_index);
    }

    // else{
    // 	cout<<"invalid entry"<<endl;
    // }

    //cout <<endl;

	}
}