#include <iostream>
#include <vector>
using namespace std;

//Edge Properties
struct Edge {
	double edge_distance;
};

//Creating a city
struct City {
	string city_name;
	double shortest_distance;
	int degree;  //signified the number of adjacent verticies connected 

	Edge distance_from_src;
	string parent;
	bool min_extracted;
	City* next_city;
};


struct Vertex{
	City* first_node; //maybe pointer
	Vertex* next_vertex;
};


class undirectedGraph{
	private: 
	Vertex* vertex_head;
	Vertex* vertex_tail;
	int no_of_nodes; 
	int no_of_edges;
	int no_of_min_extracted;

	public: 
	undirectedGraph();
	~undirectedGraph();

	void insert_city(string name); 
	void setd(string name1, string name2, double d); 
	void setd_helper(string name1, string name2, double d);
	void search_city(string name);

	void print_degree(string name); /*Number of directed edges from this point- bidirectional means 1*/
	void graph_nodes();
	void graph_edges(); 

	void print_distance(string name1, string name2); /*Cities must be adjacent*/
	void print_shortest_distance(string name1, string name2);
	void generate_shortest_distance(string name1, string name2);
	void set_min_extracted(Vertex *min_vertex);
	bool check_if_names_exist(string name1, string name2);
	Vertex* findmin();
	void relax(City* u, City* v);
	void modifyCity(City* v);
	//void evaluate_no_of_min_extracted();
	void initialization_shortest_distance(string name1, string name2);
	void print_path_shortest_distance(string name1, string name2);

	void clear(); 
	Vertex* find_city(string name);
};