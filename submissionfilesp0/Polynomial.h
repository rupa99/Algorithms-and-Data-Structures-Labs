// Polynomial.h
// Class interface/header file for  polynomial
// Author: Tiuley Alguindigue (Aug 2019)

//https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/

#include <iostream>
using namespace std;
    
// Polynomial for single variable X


class Polynomial {

    //YOU need this inside to use THIS
    struct Coeff_List
    {
        double coeff;
        struct Coeff_List *next_coeff;
    };

    // class variables
	private:
	int size, size_p2, size_sum;  // degree + 1
    public:
    Coeff_List *start, *end, *start_p2, *end_p2, *start_sum, *end_sum, *start_prod, *end_prod;

    // class functions
    public:
    Polynomial (int x, const double coeff_p[]);
    Polynomial();
    ~Polynomial();
	
    
    void init(int m); 

    void coeff_p1(const Polynomial &current_polynomial)  ;
    void coeff_p2(int expected_size, const double expected_coeff_p[]); 

    void get(int expected_size, const double expected_coeff_p[]) const ;
    void evaluate( const double x, const double expected_value) const; 
    void add(int expected_size, const double expected_coeff_p[]) const;
    void mult(int expected_size, const double expected_coeff_p[]) const; 

   
    Polynomial operator+(const Polynomial& right); 
    void add_coeff_to_list(double x);
    void add_p2coeff_to_list(double x);
    void add_temp_coeff_to_list(double x);
    void add_temp_mult_coeff_to_list(double x);
   
    double Retrive_nth_node(int index, int size_x, Coeff_List* start_node) const;
    void Add_to_nth_node (int index, double value_to_add, int size_x);

  

};
