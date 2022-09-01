#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include <regex>
#include "undirectedGraph.cpp"

using namespace std;

int main(){
	string line = "";
  	string word = "";
  	string individual_word = "";
    undirectedGraph u;

  
  	while (getline(cin, line)) {

  		stringstream singleline(line);
    	getline(singleline, word, ' ');

    	if(word == "i"){
 		 string city_name(""); 

    	//cout<<"I'm in i "<<endl; 
    	while(singleline >> word){
       		string add(word);
       		city_name.append(" ");
       		city_name.append(add);
    	}
     	
     	//cout<<"the name is "<<city_name<<endl;
      city_name = regex_replace(city_name, regex("^\\s++"), string(""));
      u.insert_city(city_name); 

    	}

    	else if (word == "setd" ){
      	
   		string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}
      	stringstream whole_word(init);
      	int index =0; 
      	string name1, name2, distance_str; 
      	double d = 0; 
      	

      	while(getline(whole_word, individual_word, ';')){
      		if(index == 0){
      			name1 = individual_word; 
            name1 = regex_replace(name1, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

      		else if(index == 1){
      			name2 = individual_word; 
            name2 = regex_replace(name2, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

      		else if(index == 2){
      			distance_str = individual_word;
      			stringstream dist(distance_str);
      			dist >> d;
      			index++; 
      			break;
      		}

      	}

      //cout<<"name1 ="<<name1<<", "<<"name2 ="<<name2<<", "<<"distance="<<d<<endl;
      u.setd(name1, name2, d);

  	}

    else if(word == "s"){
       string search_name(""); 

      //cout<<"I'm in i "<<endl; 
      while(singleline >> word){
          string add(word);
          search_name.append(" ");
          search_name.append(add);
      }
      
      //cout<<"the degree is="<<degree<<endl;
      search_name = regex_replace(search_name, regex("^\\s++"), string(""));
      u.search_city(search_name);
      //cout<<"search"<<search_name<<endl;

    }

  	else if(word == "degree"){
 		  string degree(""); 

    	//cout<<"I'm in i "<<endl; 
    	while(singleline >> word){
       		string add(word);
       		degree.append(" ");
       		degree.append(add);
    	}
     	degree = regex_replace(degree, regex("^\\s++"), string(""));
     //	cout<<"the degree is="<<degree<<endl;
      u.print_degree(degree);

    }


    else if(word == "graph_nodes"){

     	//cout<<"graph nodes"<<endl;
      u.graph_nodes();

    }

    else if(word == "graph_edges"){
    	
     //	cout<<"graph edges"<<endl;
      u.graph_edges();

    }

    else if(word == "d"){
    	
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}
      	stringstream whole_word(init);
      	int index =0; 
      	string name1, name2; 

      	while(getline(whole_word, individual_word, ';')){
      		if(index == 0){
      			name1 = individual_word; 
            name1 = regex_replace(name1, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

      		else if(index == 1){
      			name2 = individual_word;
            name2 = regex_replace(name2, regex("^\\s++"), string("")); 
      			index++; 
      			continue;
      		}

    	}

    	//cout<<"name1 ="<<name1<<", "<<"name2 ="<<name2<<endl;
      u.print_distance(name1, name2);

	}

	 else if(word == "shortest_d"){
    	
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}
      	stringstream whole_word(init);
      	int index =0; 
      	string name1, name2; 

      	while(getline(whole_word, individual_word, ';')){
      		if(index == 0){
      			name1 = individual_word; 
            name1 = regex_replace(name1, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

      		else if(index == 1){
      			name2 = individual_word;
            name2 = regex_replace(name2, regex("^\\s++"), string("")); 
      			index++; 
      			continue;
      		}

    	}

    	//cout<<"name1 ="<<name1<<", "<<"name2 ="<<name2<<endl;
      u.print_shortest_distance(name1, name2);
	}

	 else if(word == "print_path"){
    	
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}
      	stringstream whole_word(init);
      	int index =0; 
      	string name1, name2; 

      	while(getline(whole_word, individual_word, ';')){
      		if(index == 0){
      			name1 = individual_word; 
            name1 = regex_replace(name1, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

      		else if(index == 1){
      			name2 = individual_word; 
            name2 = regex_replace(name2, regex("^\\s++"), string(""));
      			index++; 
      			continue;
      		}

    	}

    	//cout<<"name1 ="<<name1<<", "<<"name2 ="<<name2<<endl;
      u.print_path_shortest_distance(name1,name2);
	}

	else if(word == "clear"){
    	
    	//cout<<"clear"<<endl;
      u.clear();
    }








}

}
