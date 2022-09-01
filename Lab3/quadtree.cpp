#include <iostream>
#include <bits/stdc++.h>
#include "quadtree.h"
#include <string>
#include <regex>
using namespace std;

quadtree::quadtree(){
	root = NULL;
	tree_size = 0;

	total_Population =0;
	total_Cost_Of_Living = 0;
	total_Average_Net_Salary =0;

	max_Population =0;
	max_Cost_Of_Living = 0;
	max_Average_Net_Salary =0;

	min_Population =0;
	min_Cost_Of_Living = 0;
	min_Average_Net_Salary =0;

	prev_comparison_value = 0;
	prev_comparison_value_min = 10000000;


	
}

quadtree::~quadtree(){
}

void quadtree::insert_city(string Name, double Longitude, double Latitude, long int Population, long int Cost_Of_Living, long int Average_Net_Salary){
	

	Node* new_city = new Node;

	new_city -> Location = Key(Longitude, Latitude);
	new_city -> Attribute = Value(Name, Population, Cost_Of_Living, Average_Net_Salary);
	new_city -> NW = NULL;
	new_city -> NE = NULL;
	new_city -> SE = NULL;
	new_city -> SW = NULL;

	if(root == NULL) {
		root = new_city; 
		cout<<"success"<<endl;
		tree_size++;
	}
	else{
		//cout<<"entered the helper"<<endl;
		if(insertion_helper(root, new_city) == NULL){
			cout<<"failure"<<endl;
		}
		else{
			tree_size++;
			cout<<"success"<<endl;
		}
	}
	//cout<<"x value ="<<new_city -> Location.x_Longitude<<endl;

}

struct Node* quadtree::insertion_helper(struct Node* current_node, struct Node* new_city){
	//cout<<"entered helper"<<endl;
	//cout<<"came into helper for city"<<new_city->Attribute.Name<<endl;
	//cout<<"current_node"<<current_node ->Attribute.Name<<endl;
	if(current_node == NULL){
		//cout<<"in the null loop"<<endl;
		return new_city;

	}

	double inserting_node_x = new_city -> Location.x_Longitude; 
	double current_node_x = current_node -> Location.x_Longitude; 
	
	// cout<<"inset x= "<<inserting_node_x<<endl;
	// cout<<"current_node x="<<current_node_x<<endl;

	double inserting_node_y = new_city -> Location.y_Latitude; 
	double current_node_y = current_node -> Location.y_Latitude; 
	
	if(inserting_node_x == current_node_x && inserting_node_y == current_node_y){
		return NULL;
	}
	//go to the NE child
	else if( inserting_node_x >= current_node_x && inserting_node_y > current_node_y){
		//cout<<"went into the NE"<<endl;
		Node * temp = insertion_helper(current_node -> NE, new_city);
		if(temp != NULL){
			current_node -> NE = temp; 
		}
		else{
			return NULL;
		}
	}
 
	//go to the NW child
	else if(inserting_node_x < current_node_x && inserting_node_y >= current_node_y){
		//cout<<"went into the NW"<<endl;
		Node * temp = insertion_helper(current_node -> NW, new_city);
		if(temp != NULL){
			current_node -> NW = temp;
		}
		else{
			return NULL;
		}
	}

	//go to the SW child
	else if(inserting_node_x <= current_node_x && inserting_node_y < current_node_y){
		//cout<<"went into the SW"<<endl;
		Node* temp = insertion_helper(current_node -> SW, new_city);
		if(temp != NULL){
			current_node -> SW = temp;
		}
		else{
			return NULL;
		}
	}

	//go to the SE child
	else if(inserting_node_x > current_node_x && inserting_node_y <= current_node_y){
		//cout<<"went into the SE"<<endl;
		Node* temp = insertion_helper(current_node -> SE, new_city);
		if(temp != NULL){
			current_node -> SE = temp; 
		}
		else{
			return NULL;
		}
	}
	//cout<<"didn't go into any loop"<<endl;
	return current_node;

}

struct Node* quadtree::search_helper(struct Node* current_node, double Longitude, double Latitude){
	
	double searching_x = Longitude; 
	double current_node_x = current_node -> Location.x_Longitude; 

	double searching_y = Latitude; 
	double current_node_y = current_node -> Location.y_Latitude; 

	if(current_node == NULL){
		cout<<"in here"<<endl;
		return NULL;
	}
	

	if(current_node_x == searching_x && current_node_y == searching_y){
		//cout<<"in the thing"<<endl;
		//search_result = current_node->Attribute.Name; 
		return current_node; 
	}

	if(searching_x >= current_node_x && searching_y>current_node_y){
		if(current_node -> NE != NULL){
			return search_helper(current_node-> NE, Longitude, Latitude);
		}
		else{
			return NULL;
		}
	}

	else if(searching_x < current_node_x && searching_y >= current_node_y){
		if(current_node -> NW != NULL){
			return search_helper(current_node -> NW, Longitude, Latitude);
		}
		else{
			return NULL;
		}

	}

	else if(searching_x <= current_node_x && searching_y <current_node_y){
		if(current_node -> SW != NULL){
			return search_helper(current_node -> SW, Longitude, Latitude);		

		}
		else{
			return NULL;
		}

	}

	else if(searching_x > current_node_x && searching_y <= current_node_y){
		if(current_node -> SE != NULL){
			return search_helper(current_node -> SE, Longitude, Latitude);
		}
		else{
			return NULL;
		}

	}

}

void quadtree::search_node(double Longitude, double Latitude){
	
	 
	//cout<<"Function: Search the node"<<endl;

	if(root == NULL){
		cout<<"not found"<<endl;
	}
	else {
		Node* temp = search_helper(root, Longitude, Latitude); 
		
		if(temp== NULL){
			cout<<"not found"<<endl;
		}
		else if(temp!= NULL){
			cout<<"found "<<temp ->Attribute.Name<<endl;
		}
	}
}

struct Node* quadtree::max_population(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	max_population(current_node -> NE); 
        	max_population(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Population; 
        	if(current_value > prev_comparison_value){
        		prev_comparison_value = current_value; 
        	}
        	max_population(current_node -> SW); 
        	max_population(current_node -> SE);
    	} 
}

struct Node* quadtree::max_cost_Of_Living(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	max_cost_Of_Living(current_node -> NE); 
        	max_cost_Of_Living(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Cost_Of_Living; 
        	if(current_value > prev_comparison_value){
        		prev_comparison_value = current_value; 
        	}
        	max_cost_Of_Living(current_node -> SW); 
        	max_cost_Of_Living(current_node -> SE);
    	} 
}

struct Node* quadtree::max_average_Net_Salary(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	max_average_Net_Salary(current_node -> NE); 
        	max_average_Net_Salary(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Average_Net_Salary; 
        	if(current_value > prev_comparison_value){
        		prev_comparison_value = current_value; 
        	}
        	max_average_Net_Salary(current_node -> SW); 
        	max_average_Net_Salary(current_node -> SE);
    	} 
}


long int quadtree::q_max_helper(struct Node* current_node, string attr){
	if(attr == "p"){
		max_population(current_node);
		return prev_comparison_value;
	
	}
	else if(attr == "r"){
		max_cost_Of_Living(current_node);
			return prev_comparison_value;
	
	}
	else if(attr == "s"){
		max_average_Net_Salary(current_node);
		return prev_comparison_value;
	}

}


void quadtree::find_q_max(double Longitude, double Latitude, string Direction, string attr){
	
// cout<<"Function: find qmax"<<endl;
if(root == NULL){
		cout<<"failure"<<endl;
	}
	else {
		Node* temp = search_helper(root, Longitude, Latitude); 
		
		if(temp== NULL){
			cout<<"failure"<<endl;
		}
		else if(temp!= NULL){
			if(Direction =="NE"){
				if(temp->NE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NE; 
					long int max = q_max_helper(temp, attr);

					max_Population =0;
					max_Cost_Of_Living = 0;
					max_Average_Net_Salary =0;
					prev_comparison_value = 0;

					cout<<"max "<<max<<endl;
				}
			}
			else if(Direction == "NW"){
				if(temp->NW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NW; 
					long int max = q_max_helper(temp, attr); 

					max_Population =0;
					max_Cost_Of_Living = 0;
					max_Average_Net_Salary =0;
					prev_comparison_value = 0;

					cout<<"max "<<max<<endl;
				}
			}
			else if(Direction == "SW"){
				if(temp->SW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SW; 
					long int max = q_max_helper(temp, attr); 

					max_Population =0;
					max_Cost_Of_Living = 0;
					max_Average_Net_Salary =0;
					prev_comparison_value = 0;

					cout<<"max "<<max<<endl;
				}

			}
			else if(Direction == "SE"){
				if(temp->SE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SE; 
					long int max = q_max_helper(temp, attr); 

					max_Population =0;
					max_Cost_Of_Living = 0;
					max_Average_Net_Salary =0;
					prev_comparison_value = 0;

					cout<<"max "<<max<<endl;
				}
			}

		}
	}


}




struct Node* quadtree::min_population(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	min_population(current_node -> NE); 
        	min_population(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Population; 
        	if(current_value < prev_comparison_value_min){
        		prev_comparison_value_min = current_value; 
        	}
        	min_population(current_node -> SW); 
        	min_population(current_node -> SE);
    	} 
}

struct Node* quadtree::min_cost_Of_Living(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	min_cost_Of_Living(current_node -> NE); 
        	min_cost_Of_Living(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Cost_Of_Living; 
        	if(current_value < prev_comparison_value_min){
        		prev_comparison_value_min = current_value; 
        	}
        	min_cost_Of_Living(current_node -> SW); 
        	min_cost_Of_Living(current_node -> SE);
    	} 
}

struct Node* quadtree::min_average_Net_Salary(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	min_average_Net_Salary(current_node -> NE); 
        	min_average_Net_Salary(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Average_Net_Salary; 
        	if(current_value < prev_comparison_value_min){
        		prev_comparison_value_min = current_value; 
        	}
        	min_average_Net_Salary(current_node -> SW); 
        	min_average_Net_Salary(current_node -> SE);
    	} 
}


long int quadtree::q_min_helper(struct Node* current_node, string attr){
	if(attr == "p"){
		min_population(current_node);
		return prev_comparison_value_min;
	
	}
	else if(attr == "r"){
		min_cost_Of_Living(current_node);
			return prev_comparison_value_min;
	
	}
	else if(attr == "s"){
		min_average_Net_Salary(current_node);
		return prev_comparison_value_min;
	}
}

void quadtree::find_q_min(double Longitude, double Latitude, string Direction, string attr){
	
if(root == NULL){
		cout<<"failure"<<endl;
	}
	else {
		Node* temp = search_helper(root, Longitude, Latitude); 
		
		if(temp== NULL){
			cout<<"failure"<<endl;
		}
		else if(temp!= NULL){
			if(Direction =="NE"){
				if(temp->NE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NE; 
					long int min = q_min_helper(temp, attr);

					min_Population =0;
					min_Cost_Of_Living = 0;
					min_Average_Net_Salary =0;
					prev_comparison_value_min = 10000000;

					cout<<"min "<<min<<endl;
				}
			}
			else if(Direction == "NW"){
				if(temp->NW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NW; 
					long int min = q_min_helper(temp, attr); 

					min_Population =0;
					min_Cost_Of_Living = 0;
					min_Average_Net_Salary =0;
					prev_comparison_value_min = 10000000;

					cout<<"min "<<min<<endl;
				}
			}
			else if(Direction == "SW"){
				if(temp->SW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SW; 
					long int min = q_min_helper(temp, attr); 

					min_Population =0;
					min_Cost_Of_Living = 0;
					min_Average_Net_Salary =0;
					prev_comparison_value_min = 10000000;

					cout<<"min "<<min<<endl;
				}

			}
			else if(Direction == "SE"){
				if(temp->SE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SE; 
					long int min = q_min_helper(temp, attr); 

					min_Population =0;
					min_Cost_Of_Living = 0;
					min_Average_Net_Salary =0;
					prev_comparison_value_min = 10000000;

					cout<<"min "<<min<<endl;
				}
			}

		}
	}

}

struct Node* quadtree::total_population(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	total_population(current_node -> NE); 
        	total_population(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Population; 
        	total_Population = total_Population + current_value;  
        	total_population(current_node -> SW); 
        	total_population(current_node -> SE);
    	} 
}

struct Node* quadtree::total_cost_Of_Living(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	total_cost_Of_Living(current_node -> NE); 
        	total_cost_Of_Living(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Cost_Of_Living; 
        	total_Cost_Of_Living = total_Cost_Of_Living + current_value;  
        	total_cost_Of_Living(current_node -> SW); 
        	total_cost_Of_Living(current_node -> SE);
    	} 
}

struct Node* quadtree::total_average_Net_Salary(struct Node* current_node){
	if (current_node != NULL) 
    	{ 
        	total_average_Net_Salary(current_node -> NE); 
        	total_average_Net_Salary(current_node -> NW); 
        	long int current_value = current_node -> Attribute.Average_Net_Salary; 
        	total_Average_Net_Salary = total_Average_Net_Salary + current_value;  
        	total_average_Net_Salary(current_node -> SW); 
        	total_average_Net_Salary(current_node -> SE);
    	}

}

long int  quadtree::q_total_helper(struct Node* current_node, string attr){
	if(attr == "p"){
		total_population(current_node);
		return total_Population;
	
	}
	else if(attr == "r"){
		total_cost_Of_Living(current_node);
		return total_Cost_Of_Living;
	
	}
	else if(attr == "s"){
		total_average_Net_Salary(current_node);
		return total_Average_Net_Salary;
	}

}

void quadtree::find_q_total(double Longitude, double Latitude, string Direction, string attr){
	//cout<<"Function: find qtotal"<<endl;

if(root == NULL){
		cout<<"failure"<<endl;
	}
	else {
		Node* temp = search_helper(root, Longitude, Latitude); 
		
		if(temp== NULL){
			cout<<"failure"<<endl;
		}
		else if(temp!= NULL){
			if(Direction =="NE"){
				if(temp->NE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NE; 
					long int total = q_total_helper(temp, attr);

					total_Population =0;
					total_Cost_Of_Living = 0;
					total_Average_Net_Salary =0;

					cout<<"total "<<total<<endl;
				}
			}
			else if(Direction == "NW"){
				if(temp->NW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> NW; 
					long int total = q_total_helper(temp, attr); 

					total_Population =0;
					total_Cost_Of_Living = 0;
					total_Average_Net_Salary =0;

					cout<<"total "<<total<<endl;
				}
			}
			else if(Direction == "SW"){
				if(temp->SW==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SW; 
					long int total = q_total_helper(temp, attr); 

					total_Population =0;
					total_Cost_Of_Living = 0;
					total_Average_Net_Salary =0;

					cout<<"total "<<total<<endl;
				}

			}
			else if(Direction == "SE"){
				if(temp->SE==NULL){
					cout<<"failure"<<endl;
				}
				else{
					temp = temp -> SE; 
					long int total = q_total_helper(temp, attr); 

					total_Population =0;
					total_Cost_Of_Living = 0;
					total_Average_Net_Salary =0;

					cout<<"total "<<total<<endl;
				}
			}

		}
	}
}

//Inorder Print- NE, NW, ROOT, SW, SE -- city name 
void quadtree::print(){
	//cout<<"Function: Print"<<endl; 
	inorder_print_helper(root);
	cout<<endl;
	
}

void quadtree::inorder_print_helper(struct Node* current_node){
	//cout<<current_node->Attribute.Name<<endl; 
	//cout<<current_node->NW->Attribute.Name<<endl;
	if (current_node != NULL) 
    	{ 
        	inorder_print_helper(current_node -> NE); 
        	inorder_print_helper(current_node -> NW); 
        	cout<<regex_replace(current_node->Attribute.Name, regex("^\\s++"), string(""))<<" "; 
        	inorder_print_helper(current_node -> SW); 
        	inorder_print_helper(current_node -> SE);
    	} 
}



void quadtree::clear(){
	root = NULL;
	tree_size = 0;

	cout<<"success"<<endl;
}

void quadtree::size(){
	//cout<<"Function: Size"<<endl;
	cout<<"tree size "<<tree_size<<endl;
}