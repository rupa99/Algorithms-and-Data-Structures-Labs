#include <iostream>
#include <sstream>
#include <bits/stdc++.h> 

using namespace std; 

int main(){

	string line = ""; 
	string word = ""; 
	int count = 0; 

	while(getline(cin, line)){

	stringstream singleline(line);

	getline(singleline, word, ' ');



    if(word == "i"){
 		string init(""); 

    	cout<<"I'm in i "<<endl; 
    	while(singleline >> word){
       		string add(word);
       		init.append(" ");
       		init.append(add);
       		count++; 
    	}
    	cout <<"the word in i is = "<<init<<endl;
    	cout<<"The number of words is = "<<count<<endl; 
    	count =0; 

    }

    else if (word == "p" ){
    	cout<<"I'm in p "<<endl; 
    	while(singleline >> word) {
       		cout <<"the number in p is = "<<stoi(word)<<endl; 
       		count++; 
    	}
    	cout<<"The number of words is = "<<count<<endl; 
    	count =0; 
    }

    else if (word == "e"){
    	cout<<"I'm in e "<<endl;
    	while(singleline >> word) {
       		cout <<"the number in e is = "<<stoi(word)<<endl; 
       		count++; 
    	}
    	cout<<"The number of words is = "<<count<<endl; 
    	count =0; 


    }

    else{
    	cout<<"invalid entry"<<endl;
    }

    cout<<endl; 


	}
}