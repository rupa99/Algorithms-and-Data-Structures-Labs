#include <iostream>
#include<cmath>
#include <array>
#include <iterator>
#include<cstdlib>
#include <vector>
#include<string.h>
using namespace std; 

#include "playlist.h"

playlist::playlist(){ 

}

playlist::~playlist() {
 	
 }

 void playlist::initialize_song(string song_artist){ 
 	//cout<<"Function:Initialize song"<<endl; 
 
 	if(playlist_obj.empty()){
 		playlist_obj.push_back(song_artist);
 		cout<<"success"<<endl;	
 	}

 	else{
 		bool is_match = match_checker(song_artist);
 		if(is_match){
			cout<<"can not insert"<<song_artist<<endl;
		}
		else{
			playlist_obj.push_back(song_artist);
			cout<<"success"<<endl;		}
 	}

 }

  void playlist::play_song(int song_number){
 	//cout<<"Function:playing song"<<endl; 
 	if(playlist_obj.empty()){
 		cout<<"could not play "<<song_number<<endl; 
 	}
 	else if(song_number == 0){
 		cout<<"could not play "<<song_number<<endl; 
 	}
 	else if(song_number > (playlist_obj.size())){
 		cout<<"could not play "<<song_number<<endl;  
 	}
 	else{
 		for (int i = 0; i < playlist_obj.size(); i++) {
 			if(song_number == (i+1)){
 				cout<<"played "<<song_number<<playlist_obj[i]<<endl;
 				break; 
 			}
 		}
       			 
 	}

 }

 void playlist::erase_song(int song_number){ 
 	//cout<<"Function:erasing song"<<endl; 
 	if(playlist_obj.empty()){
 		cout<<"could not erase "<<song_number<<endl; 
 	}
 	else if(song_number == 0){
 		cout<<"could not erase "<<song_number<<endl; 
 	}
 	else if(song_number > (playlist_obj.size())){
 		cout<<"could not erase "<<song_number<<endl; 
 	}
 	else{
 		for (int i = 0; i < playlist_obj.size(); i++) {
 			if(song_number == (i+1)){
 				//cout<<"Song going to be erased = "<<(playlist_obj.begin()+i)<<endl;
 				playlist_obj.erase(playlist_obj.begin()+i);
 				cout<<"success"<<endl;
 				// cout<<"song erased"<<endl;
 				// cout<<"new vector elements are "<<endl; 
 				// printnewvector(); 
 				break; 
 			}
 		}
       			 
 	}

 }

  bool playlist::match_checker(string song_artist){ 
 	for(auto x: playlist_obj){
 		if(x == song_artist){
 			return true; 
 		}
 	}
 	return false;
 }

 void playlist::printnewvector(){
 	for(auto x: playlist_obj){
 		cout<<x<<endl; 
 	}

 }


