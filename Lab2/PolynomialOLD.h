// Polynomial.h
// Class interface/header file for  polynomial
// Author: Tiuley Alguindigue (Aug 2019)

//SOURCE: Linked List - https://www.codesdope.com/blog/article/c-linked-lists-in-c-singly-linked-list/ 

#include <iostream>
using namespace std;

// Polynomial for single variable X

class Polynomial {

    struct node
    {        
        int coefficient;
        node *next;
    };    

    // class variables
	private:
	int size ; 
    double *coeff_list; 
    node *head,*tail; 


    // class functions
    public:
    Polynomial (const int& size_p, const double coeff_p[]);
    Polynomial();
    ~Polynomial();

    // copy constructor and equal operator
    Polynomial (const Polynomial &polynomial_to_copy);
    Polynomial& operator=(const Polynomial& other) ;


    // add and +
	Polynomial add( const Polynomial& right) const ;
	Polynomial operator+(const Polynomial& right) ;


    //evaluate a polynomial
    void evaluate( const double x, const double expected_value) const;

    // print the polynomial
    void print();

    //initilizes the size of the polynomial
     void add_coeff(const double x) const; 
     double retrive_coeff(node* head, int index);
    // void init(int m); 
    // void coeff_p1(const double coeff_p1[]); 
    // void get(const Polynomial &expected_polynomial) const;



};
