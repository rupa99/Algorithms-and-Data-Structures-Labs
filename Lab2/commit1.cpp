// Polynomial.cpp - implementation file for Polynomial class
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
#include<cmath>
using namespace std;

#include "Polynomial.h"
//UPDATE TO THIS!! 



Polynomial::Polynomial (const int& size_p, const double coeff_p[]) {
 	size= size_p;

 	start = NULL;
    end = NULL;


    for(int i = 0; i < size_p; i++){
    		add_coeff_to_list(coeff_p[i]);
	}


 }


 Polynomial::Polynomial() {

 	size = 0;
 	start = NULL;
    end = NULL;

 }

 // destructor
 Polynomial::~Polynomial() {
 	delete start ; // delete array that starts at address stored in coeff
 	delete end ; //
 }
 
void Polynomial::init(int m){
	size = m; 
	cout << "FUNCTION init: " <<'\n'<< "success "<<"expected m = "<<m<< " , actual size is = "<< size << endl << '\n';  
	 
}

void Polynomial::coeff_p1(const double coeff_p1[]){
	cout << "FUNCTION coeff_p1: " <<'\n'; 

    for(int i = 0; i < size; i++){
    		add_coeff_to_list(coeff_p1[i]);
	}

	cout << '\n'<<"success" << endl<< '\n'; 

}


void Polynomial::get(const Polynomial &expected_polynomial) const  { 
	cout <<"FUNCTION get: " <<'\n';  
	bool Isequal = false;  

	//CASE 1: Compare the size 
	if(expected_polynomial.size == this ->size){ 
		for(int i = 0; i < this -> size;i++){ 
			if((this->Retrive_nth_node(i))==(expected_polynomial.Retrive_nth_node(i))){ //this you can use ->, else . 
				cout<<"value p1 = "<<this ->Retrive_nth_node(i)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i)<<endl; 
				Isequal = true; 
				continue;  
			}  else{ 
			cout<<"value p1 = "<<this ->Retrive_nth_node(i)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i)<<endl; 
			Isequal = false;  
			break;
 } 
} 
}

	if(Isequal == true){
		cout << "success: " << " the polynomials are equal" << endl << '\n'; 
	}
	else{
		cout << "failure: " << "the polynomials are not equal" << endl <<'\n';  
	}

}


void Polynomial::evaluate( const double x, const double expected_value) const {
 	cout << "FUNCTION evaluate: " <<'\n'; 
 	
 	double evaluation_value = 0; 
 	int term_value = 0; 
 	double constantvalue =0; 
 	int input = 0; 

 	input = x; 
 	
 	for(int i = 0; i < size; i++){ 
 		term_value = i; 
 		if(i==0){
 			constantvalue = Retrive_nth_node(i); 
 			evaluation_value = evaluation_value + constantvalue; 
 			continue;
 		}
 		evaluation_value = evaluation_value + (pow(input, term_value)*(Retrive_nth_node(i)));
 		
 	}
 	
 	if(expected_value == evaluation_value ){
 		cout << "success" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 	}

 	else{
 		cout << "failure" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 	}

}

void Polynomial::add_coeff_to_list(double x) {  //TODO: Check similarity 
        
        Coeff_List *tmp_node = new Coeff_List;
        tmp_node->coeff = x;
        tmp_node->next_coeff = NULL;

        if(start == NULL)
        {

            start = tmp_node;
            end = tmp_node;
        }
        else
        {
            end->next_coeff = tmp_node;
            end = end->next_coeff;
              }
    }


double Polynomial::Retrive_nth_node (int index) const { //making the sub-functions const to ensure no permanent change
      
    Coeff_List* current_node = start;  
     
    for( int i=0; i< size ; i++){
    	if (i == index)  {
            return (current_node-> coeff) ;  
        }
        else{
        	 current_node = current_node->next_coeff;  
        }
    }

}




/*
1) create a p2 head and tail pointer 
2) Update the add first, (then retrive) to add specific to the head 
3) Check, then update the retrive!


**/




























// polynomialtest.cpp - Test file  Polynomial class (as array)
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
using namespace std;

#include "Polynomial.h" // Class to represent polynomials

int main()
{
		cout<<"Test 1:" <<endl; 

		double p6_array[] = {1.0,3.3};
		Polynomial p6; 
		p6.init(2);
		p6.coeff_p1(p6_array);


	    double Test1_parray[] = {1.0,3.3};
		Polynomial Test1_p(2,Test1_parray);
		p6.get(Test1_p); 

		p6.evaluate(2,7.6);


		return 0;

}





























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
	int size ;  // degree + 1
    public:
    Coeff_List *start, *end;

    // class functions
    public:
    Polynomial (const int& size_p, const double coeff_p[]);
    Polynomial();
    ~Polynomial();
	
    // add and +
	//Polynomial add( const Polynomial& right) const ;

    //evaluate a polynomial
   // double evaluate( const double &x) const ;
    
    void init(int m); 
    void coeff_p1(const double coeff_p1[]);
    void get(const Polynomial &expected_polynomial) const;
   void evaluate( const double x, const double expected_value) const; 


    void add_coeff_to_list(double x);
    double Retrive_nth_node(int index) const;
    // print the polynomial
   // void print();

};
