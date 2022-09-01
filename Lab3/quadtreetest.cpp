#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "quadtree.cpp"

using namespace std;

/*TODO: Unsigened long int*/

int main(){

	  string line = "";
  	string word = "";
  	string individual_word = "";
  	quadtree p1;

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
      	stringstream whole_word(init);
      	int index =0; 

      	string Name;
        long int Population, Cost_Of_Living, Average_Net_Salary;
      	double Longitude, Latitude;

      	while(getline(whole_word, individual_word, ';')){
      		//whole_word>>individual_word;
      		if(index == 0){
    			Name = individual_word;
    			index++;
    			continue;
      		}
      		if(index == 1){
      			Longitude = stod(individual_word); 
      			index++;
      			continue;
      		}

      		if(index ==2){
      			Latitude = stod(individual_word); 
      			index++;
      			continue;

      		}

      		if(index == 3){
      			Population = stol(individual_word); 
      			index++;
      			continue;
      		}

      		if(index == 4){
      			Cost_Of_Living = stol(individual_word); 
      			index++;
      			continue;
      		}

      		if(index == 5){
      			Average_Net_Salary =  stol(individual_word); 
      			index++;
      			break;
      		}

      	}
    	// 	cout<<"init ="<<init<<endl;
       	// 	cout<<endl;
      	// cout<<"Name = "<<Name<<endl; 
      	// cout<<"Longitude = "<<Longitude<<endl;
      	// cout<<"Latitude = "<<Latitude<<endl; 
      	//cout<<"Population = "<<Population<<endl;
      	// cout<<"Cost_Of_Living = "<<Cost_Of_Living<<endl; 
      	// cout<<"Average_Net_Salary = "<<Average_Net_Salary<<endl;
      	p1.insert_city(Name, Longitude, Latitude, Population, Cost_Of_Living, Average_Net_Salary);

    } 

    if(word == "s"){
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}
      	stringstream whole_word(init);
      	int index =0; 
      	double Longitude, Latitude; 

      		while(getline(whole_word, individual_word, ';')){
      			if(index == 0){
      				Longitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==1){
      				Latitude = stod(individual_word); 
      				index++;
      				break;
      			}
      		}
      		p1.search_node(Longitude, Latitude);
      		// cout<<"longitude ="<<Longitude<<endl;
      		// cout<<"latitude ="<<Latitude<<endl;
    }

    else if(word == "q_max"){
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}

      	stringstream whole_word(init);
      	int index =0; 

      	string Attr, Direction;
      	double Longitude, Latitude; 

      	while(getline(whole_word, individual_word, ';')){
      			if(index == 0){
      				Longitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==1){
      				Latitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==2){
      				Direction = individual_word; 
      				index++;
      				continue;	
      			}

      			if(index ==3){
      				Attr = individual_word; 
      				index++;
      				break;
      			}
      		}
      		p1.find_q_max(Longitude, Latitude, Direction, Attr);
      		// cout<<"longitude ="<<Longitude<<endl;
      		// cout<<"latitude ="<<Latitude<<endl;
      		// cout<<"direction= "<<Direction<<endl;
      		// cout<<"attribute= "<<Attr<<endl;
    	}

    	else if(word == "q_min"){
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}

      	stringstream whole_word(init);
      	int index =0; 

      	string Attr, Direction;
      	double Longitude, Latitude; 

      	while(getline(whole_word, individual_word, ';')){
      			if(index == 0){
      				Longitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==1){
      				Latitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==2){
      				Direction = individual_word; 
      				index++;
      				continue;	
      			}

      			if(index ==3){
      				Attr = individual_word; 
      				index++;
      				break;
      			}
      		}
      		p1.find_q_min(Longitude, Latitude, Direction, Attr);
      		// cout<<"longitude ="<<Longitude<<endl;
      		// cout<<"latitude ="<<Latitude<<endl;
      		// cout<<"direction= "<<Direction<<endl;
      		// cout<<"attribute= "<<Attr<<endl;
    	}

		else if(word == "q_total"){
    	string init("");

	    while (singleline >> word) {
    		string add(word);
        	init.append(" ");
        	init.append(add);
      	}

      	stringstream whole_word(init);
      	int index =0; 

      	string Attr, Direction;
      	double Longitude, Latitude; 

      	while(getline(whole_word, individual_word, ';')){
      			if(index == 0){
      				Longitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==1){
      				Latitude = stod(individual_word); 
      				index++;
      				continue;
      			}

      			if(index ==2){
      				Direction = individual_word; 
      				index++;
      				continue;	
      			}

      			if(index ==3){
      				Attr = individual_word; 
      				index++;
      				break;
      			}
      		}
      		p1.find_q_total(Longitude, Latitude, Direction, Attr);
      		// cout<<"longitude ="<<Longitude<<endl;
      		// cout<<"latitude ="<<Latitude<<endl;
      		// cout<<"direction= "<<Direction<<endl;
      		// cout<<"attribute= "<<Attr<<endl;
    	}

    else if(word == "print"){
    	p1.print();
    }

    else if(word == "clear"){
    	p1.clear();
    }

    else if (word == "size"){
    	p1.size();
    }








  	}

}