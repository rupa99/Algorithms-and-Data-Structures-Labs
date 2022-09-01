#include <iostream>
#include <bits/stdc++.h>
#include "undirectedGraph.h"
#include <string>

undirectedGraph::undirectedGraph(){
	vertex_head = NULL;
	vertex_tail = NULL;
	no_of_nodes = 0;
	no_of_edges = 0;
	no_of_min_extracted = 0;
}

undirectedGraph::~undirectedGraph(){
}

void undirectedGraph::insert_city(string name){
	
	//If the first is NULL, then we are adding a city for the first time;
	if (vertex_head == NULL){

		Vertex *temp_vertex = new Vertex;
		City *temp_city = new City;
	
   		temp_city -> city_name = name;
   		temp_city -> shortest_distance = 0;
    	temp_city -> degree = 0;
   		temp_city -> distance_from_src.edge_distance = 0;
   		temp_city -> next_city = NULL;

		temp_city -> parent = "";
		temp_city -> min_extracted = false;

   		temp_vertex -> first_node = temp_city;
   		temp_vertex -> next_vertex = NULL;

   		//vertex_head -> first_node = temp_city; 
   		vertex_head = temp_vertex;
   		vertex_tail = temp_vertex; 

   		no_of_nodes++;

   		cout<<"success"<<endl;
  		//  cout<<vertex_head->first_node->city_name<<endl;
		// cout<<vertex_head->first_node->distance<<endl;

	}

	else{
		Vertex *temp_vertex = new Vertex; 
		temp_vertex = vertex_head; 
		bool city_exists = false; 
		
		while(temp_vertex != NULL){
			//if it exists
			if(temp_vertex -> first_node -> city_name == name){
				cout<<"failure"<<endl;
				city_exists = true;
			}

			temp_vertex = temp_vertex -> next_vertex;

		}

		//we know that the city doesn't exist, so add the city as to the end;
		if(!city_exists){
			Vertex *temp_vertex2 = new Vertex;
			City *temp_city2 = new City;
		
	   		temp_city2 -> city_name = name;
	   		temp_city2 -> shortest_distance = 0;
	    	temp_city2 -> degree = 0;
	   		temp_city2 -> distance_from_src.edge_distance = 0;
   			temp_city2 -> next_city = NULL;
   			temp_city2 -> parent = "";
			temp_city2 -> min_extracted = false;

	   		temp_vertex2 -> first_node = temp_city2;
	   		temp_vertex2 -> next_vertex = NULL;

	   		vertex_tail -> next_vertex = temp_vertex2;
	   		vertex_tail = vertex_tail -> next_vertex;

	   		no_of_nodes++;

	   		cout<<"success"<<endl;
   		}

	}
	// Vertex *temp_vertex = new Vertex;
	// City *temp_city = new City;

	// temp_vertex = vertex_head;
	// while(temp_vertex != NULL){
	// 	cout<<temp_vertex ->first_node->city_name<<endl;
	// 	temp_vertex = temp_vertex -> next_vertex;
	// }

	
} 

void undirectedGraph::setd(string name1, string name2, double d){
	//cout<<"setd"<<endl;
	//1. check if name 1 and name 2 are valid source and destinations
	bool name1_exists = false; 
	bool name2_exists = false;
	bool valid_setd = false;

	Vertex *temp_vertex = new Vertex;
	City *temp_city = new City;

	temp_vertex = vertex_head;
	while(temp_vertex != NULL){
		if(temp_vertex->first_node->city_name == name1){
			name1_exists = true; 
		}
		else if(temp_vertex->first_node->city_name == name2){
			name2_exists = true; 
		}
		temp_vertex = temp_vertex -> next_vertex;
	}

	if(name1_exists && name2_exists == true){
		valid_setd = true;
	}

	if(valid_setd == true){
		
		//setting the distance in 1 direction
		setd_helper(name1, name2, d);
		//setting the distance in the other direction
		setd_helper(name2, name1, d);

		no_of_edges++;
		cout<<"success"<<endl;

		Vertex *temp_vertex4 = new Vertex; 
		temp_vertex4 = vertex_head; 

		while(temp_vertex4 != NULL){
			if(temp_vertex4 ->first_node->city_name == name1){ //limitation is that they shouldn't give you the same relatinship twice.
				//cout<<"its in"<<endl;
				temp_vertex4 ->first_node -> degree = (temp_vertex4 ->first_node -> degree) + 1;
			}

			if(temp_vertex4 ->first_node->city_name == name2){
				temp_vertex4 ->first_node -> degree = (temp_vertex4 ->first_node -> degree) + 1;
			}

		temp_vertex4 = temp_vertex4 -> next_vertex;
	}




	// Vertex *temp_vertex3 = new Vertex;
	// temp_vertex3 = vertex_head;

	// while(temp_vertex3 != NULL){

	// 	//cout<<temp_vertex3 ->first_node->city_name<<endl;

	// 	City *temp_city3 = new City;
	// 	temp_city3 = temp_vertex3 ->first_node; 

	// 	while(temp_city3 != NULL){

	// 		cout<<temp_city3 ->city_name<<" "<<"d="<<temp_city3->distance_from_src.edge_distance<<", ";
	// 		temp_city3 = temp_city3 -> next_city;
	// 	}

	// 	temp_vertex3 = temp_vertex3 -> next_vertex;
	// 	cout<<"\n";
		
	// }

	}

	else{
		cout<<"failure"<<endl;
	}

} 

void undirectedGraph::setd_helper(string name1, string name2, double d){
		Vertex *temp_vertex2 = new Vertex;
		City *temp_city2 = new City;
		City *prev_city = new City;
		bool adjacent_city_exists = false; 

		temp_vertex2 = vertex_head;

		while(temp_vertex2 != NULL){
			if(temp_vertex2->first_node->city_name == name1){
				temp_city2 = temp_vertex2->first_node;
				//temp_city2 -> degree = (temp_city2 -> degree)++;
				while(temp_city2 != NULL){
					//if the node exists
					if(temp_city2 -> city_name == name2){
						adjacent_city_exists = true;
						temp_city2->distance_from_src.edge_distance = d;	
						//break;
					}
					prev_city = temp_city2;
					temp_city2 = temp_city2 -> next_city;
				}

				if(adjacent_city_exists == false){
					City *new_city = new City;
					new_city -> city_name = name2; 
					new_city -> shortest_distance =0; 
					new_city -> degree = 0;

					new_city -> distance_from_src.edge_distance = d;
					new_city -> next_city = NULL;

					prev_city -> next_city = new_city; 
				}

				break;
			}
			temp_vertex2 = temp_vertex2 -> next_vertex;
		}

}

void undirectedGraph::search_city(string name){
	
	Vertex *temp_vertex = new Vertex;
	bool city_found = false; 
	//City *temp_city = new City;

	temp_vertex = vertex_head;
	while(temp_vertex != NULL){ //takes a maximum of O(V) time complexity! 
		//cout<<<<endl;
		if(temp_vertex ->first_node->city_name == name){
			cout<<"found "<<name<<endl;
			city_found = true;
		}

		temp_vertex = temp_vertex -> next_vertex;
	}

	if(city_found == false){
		cout<<"not found"<<endl;
	}



	//cout<<"search_city"<<endl;
	//use a beadth first algorithm 
	//1. make a queue linked list 
	//2. enque when a new adjancent is added. 
	//3. if you dont know what you are doing look at https://www.youtube.com/watch?v=oDqjPvD54Ss
}

void undirectedGraph::print_degree(string name){
	Vertex *temp_vertex = new Vertex;
	//cout<<"name"<<endl;
	//City *temp_city = new City;

	temp_vertex = vertex_head;
	while(temp_vertex != NULL){ //takes a maximum of O(V) time complexity! 
		//cout<<"in degree loop"<<endl;
		if(temp_vertex ->first_node->city_name == name){
			cout<<"degree of "<<name<<" "<<temp_vertex ->first_node->degree<<endl;
			
		}

		temp_vertex = temp_vertex -> next_vertex;
	}

	
	//cout<<"print_degree"<<endl;
}

void undirectedGraph::graph_nodes(){
	cout<<"number of nodes "<<no_of_nodes<<endl;
}
void undirectedGraph::graph_edges(){
	cout<<"number of edges "<<no_of_edges<<endl;
}

void undirectedGraph::print_distance(string name1, string name2){

	bool name1_exists = false; 
	bool name2_exists = false;
	bool name1_connected_name2 = false;
	bool valid_print = false;

	Vertex *temp_vertex = new Vertex;
	City *temp_city = new City;

	temp_vertex = vertex_head;
	while(temp_vertex != NULL){
		if(temp_vertex->first_node->city_name == name1){
			name1_exists = true; 
		}
		else if(temp_vertex->first_node->city_name == name2){
			name2_exists = true; 
		}
		temp_vertex = temp_vertex -> next_vertex;
	}

	Vertex *temp_vertex3 = new Vertex;
	temp_vertex3 = vertex_head;

	while(temp_vertex3 != NULL){

		if(temp_vertex3 -> first_node -> city_name == name1){

			City *temp_city3 = new City;
			temp_city3 = temp_vertex3 ->first_node; 

			while(temp_city3 != NULL){

			if(temp_city3 -> city_name == name2){
				name1_connected_name2 = true;
				break;
			}
			//cout<<temp_city3 ->city_name<<" "<<"d="<<temp_city3->shortest_distance<<", ";
			temp_city3 = temp_city3 -> next_city;
			}

		}

		if(name1_connected_name2){
			break;
		}
		temp_vertex3 = temp_vertex3 -> next_vertex;
		
		
	}

	if(name1_exists && name2_exists == true && name1_connected_name2){
		valid_print = true;
	}

	if(valid_print == true){

		Vertex *temp_vertex2 = new Vertex;
		City *temp_city2 = new City;

		//City *prev_city = new City;
		bool adjacent_city_exists = false; 

		temp_vertex2 = vertex_head;

		while(temp_vertex2 != NULL){
			if(temp_vertex2->first_node->city_name == name1){
				temp_city2 = temp_vertex2->first_node;
				//temp_city2 -> degree = (temp_city2 -> degree)++;
				while(temp_city2 != NULL){
					//if the node exists
					if(temp_city2 -> city_name == name2){
						cout<<"direct distance "<<name1<<" to "<<name2<<" "<<temp_city2->distance_from_src.edge_distance<<endl;
						adjacent_city_exists = true;
						break;
					}
				
					temp_city2 = temp_city2 -> next_city;
				}

				if(adjacent_city_exists == false){
					cout<<"failure"<<endl;
					//cout<<"false"<<endl;
					break;
				}

				else if(adjacent_city_exists == true){
					break;
				}
				
			}
			temp_vertex2 = temp_vertex2 -> next_vertex;
		}
	}

	else{
		cout<<"failure"<<endl;
	}
} 

void undirectedGraph::print_shortest_distance(string name1, string name2){
	cout<<"print_shortest_distance"<<endl;
	//TODO:Error check if you are asked to print the shortest distane and they dont exist
	//Case 1: if one or both the

	//what you are asked to complete;
	generate_shortest_distance(name1, name2);


	//TODO: print the response


	//TODO: Reinitialize everything
	//reinitialize_all_verticies();

}

void undirectedGraph::generate_shortest_distance(string name1, string name2){
	//initialization
	initialization_shortest_distance(name1, name2);
	
	// Vertex *min_vertex = new Vertex;
	// min_vertex = findmin(); //TODO: Fix find min - must also not be extracted
	// cout<<"printing the min vertex's shortest distance"<<min_vertex -> first_node -> shortest_distance <<endl;

	while(no_of_min_extracted != no_of_nodes){
		
		Vertex *min_vertex = new Vertex;
		min_vertex = findmin(); //the vertex witht the min is extracted.
		set_min_extracted(min_vertex);
		//TODO: Set all the min extraced to true;

		City *temp_city = new City; 
		temp_city = min_vertex -> first_node; 
		temp_city = temp_city -> next_city;

		while(temp_city != NULL){	//for each adjacent node
			//TODO:Relax the node;
			if(temp_city -> min_extracted == true){ //if the min is already extracted
				temp_city = temp_city -> next_city;
				continue;
			}
			relax(temp_city, min_vertex->first_node); 
			modifyCity(temp_city);
			temp_city = temp_city -> next_city;

		}

		//cout<<"min vertex distance"<<min_vertex->first_node->shortest_distance<<endl;
		evaluate_no_of_min_extracted();		//changes the requird value for set_min extracted
	}


	// Vertex *temp_vertex3 = new Vertex;
	// temp_vertex3 = vertex_head;

	// while(temp_vertex3 != NULL){

	// 	//cout<<temp_vertex3 ->first_node->city_name<<endl;

	// 	City *temp_city3 = new City;
	// 	temp_city3 = temp_vertex3 ->first_node; 

	// 	while(temp_city3 != NULL){

	// 		cout<<temp_city3 ->city_name<<" "<<"d="<<temp_city3->shortest_distance<<", ";
	// 		temp_city3 = temp_city3 -> next_city;
	// 	}

	// 	temp_vertex3 = temp_vertex3 -> next_vertex;
	// 	cout<<"\n";
		
	// }

	//doubwle itterator
	// while(temp_vertex2 != NULL){
	// 		if(temp_vertex2->first_node->city_name == name1){
	// 			temp_city2 = temp_vertex2->first_node;
	// 			//temp_city2 -> degree = (temp_city2 -> degree)++;
	// 			while(temp_city2 != NULL){
	// 				//if the node exists
	// 				if(temp_city2 -> city_name == name2){
						
	// 					//break;
	// 				}
					
	// 				temp_city2 = temp_city2 -> next_city;
	// 			}

			
	// 		}
	// 		temp_vertex2 = temp_vertex2 -> next_vertex;
	// 	}
}

void undirectedGraph::set_min_extracted(Vertex *min_vertex){
	string target_city_name = min_vertex -> first_node -> city_name;

	Vertex *temp_vertex3 = new Vertex;
	temp_vertex3 = vertex_head;

	while(temp_vertex3 != NULL){

		//cout<<temp_vertex3 ->first_node->city_name<<endl;
		City *temp_city3 = new City;
		temp_city3 = temp_vertex3 ->first_node; 

		while(temp_city3 != NULL){

			if(temp_city3 -> city_name == target_city_name){
				temp_city3 -> min_extracted = true;
			}

			temp_city3 = temp_city3 -> next_city;
		}

		temp_vertex3 = temp_vertex3 -> next_vertex;
		
	}
}

void undirectedGraph::relax(City* u, City* v){

	if((v -> shortest_distance) > ((u-> shortest_distance)+(v-> distance_from_src.edge_distance))){
		v -> parent = u -> city_name; 
		v -> shortest_distance = (u-> shortest_distance)+(v-> distance_from_src.edge_distance);
	}

}

void undirectedGraph::modifyCity(City* v){ //modifying the present contents everywhere
	Vertex *temp_vertex3 = new Vertex;
	temp_vertex3 = vertex_head;

	while(temp_vertex3 != NULL){

		//cout<<temp_vertex3 ->first_node->city_name<<endl;
		City *temp_city3 = new City;
		temp_city3 = temp_vertex3 ->first_node; 

		while(temp_city3 != NULL){

			if(temp_city3 -> city_name == v->city_name){
				temp_city3 -> parent = v -> parent; 
				temp_city3 -> shortest_distance = v -> shortest_distance;
			}

			temp_city3 = temp_city3 -> next_city;
		}

		temp_vertex3 = temp_vertex3 -> next_vertex;
		
	}
}

Vertex* undirectedGraph::findmin(){
	Vertex *temp_vertex3 = new Vertex;
	Vertex *itterator = new Vertex;
	int count = 0; 

	temp_vertex3 = vertex_head;
	//int no_of_min_extracted =0; 

	while(temp_vertex3 != NULL){
		if(temp_vertex3 -> first_node -> min_extracted == true){
			temp_vertex3 = temp_vertex3 -> next_vertex;
			continue;
		}
		itterator = vertex_head;
		while(itterator != NULL){

			if(itterator -> first_node -> min_extracted == true){
				itterator = itterator -> next_vertex;
				continue;
			}

			if((temp_vertex3 ->first_node ->shortest_distance) <= (itterator -> first_node -> shortest_distance)){
				count++;
				itterator = itterator -> next_vertex;
				continue;
			}
			else{
				count =0; 
				break;
			}
		}
		if(count == (no_of_nodes- no_of_min_extracted)){	//that means the value at that temp vertex is the smallest compared to all
			break;
		}

		temp_vertex3 = temp_vertex3 -> next_vertex;
	}

	return temp_vertex3;
}

void undirectedGraph::evaluate_no_of_min_extracted(){
	Vertex *temp_vertex3 = new Vertex;
	temp_vertex3 = vertex_head;
	//int no_of_min_extracted =0; 

	while(temp_vertex3 != NULL){
		if(temp_vertex3 ->first_node-> min_extracted == true){
			no_of_min_extracted++;
		}
		temp_vertex3 = temp_vertex3 -> next_vertex;
	}
	//return no_of_min_extracted;
}

void undirectedGraph::initialization_shortest_distance(string name1, string name2){
	Vertex *temp_vertex2 = new Vertex;
	City *temp_city2 = new City;

	temp_vertex2 = vertex_head;
	while(temp_vertex2 != NULL){

		temp_city2 = temp_vertex2->first_node;

		while(temp_city2 != NULL){
			if(temp_city2->city_name == name1){
				temp_city2 ->shortest_distance = 0;
			}
			else{
				temp_city2 -> shortest_distance = (2147483647); //equivalent to infinity
			}

			temp_city2 = temp_city2 -> next_city;
		}

		temp_vertex2 = temp_vertex2 -> next_vertex;
	}

	// /*printing out*/
	// Vertex *temp_vertex3 = new Vertex;
	// temp_vertex3 = vertex_head;

	// while(temp_vertex3 != NULL){

	// 	//cout<<temp_vertex3 ->first_node->city_name<<endl;

	// 	City *temp_city3 = new City;
	// 	temp_city3 = temp_vertex3 ->first_node; 

	// 	while(temp_city3 != NULL){

	// 		cout<<temp_city3 ->city_name<<" "<<"d="<<temp_city3->shortest_distance<<", ";
	// 		temp_city3 = temp_city3 -> next_city;
	// 	}

	// 	temp_vertex3 = temp_vertex3 -> next_vertex;
	// 	cout<<"\n";
		
	// }
}

void undirectedGraph::print_path_shortest_distance(string name1, string name2){
	cout<<"print_path_shortest_distance"<<endl;
}

void undirectedGraph::clear(){
	//cout<<"clear"<<endl;

	//LOOP TO PRINT OUT THE DEGREE OF EACH ONE
	Vertex *temp_vertex5 = new Vertex;
	Vertex *prev_vertex = new Vertex; 

	temp_vertex5 = vertex_head;
	while(temp_vertex5 != NULL){
	
		//cout<<"cityname = "<<temp_vertex5 ->first_node->city_name<<"degree ="<<temp_vertex5 ->first_node->degree<<endl;
		prev_vertex = temp_vertex5; 
		temp_vertex5 = temp_vertex5 -> next_vertex;
		delete prev_vertex;
	}

	no_of_edges = 0; 
	no_of_nodes = 0;
	vertex_head = NULL; 
	vertex_tail = NULL;

	cout<<"success"<<endl;
	

}