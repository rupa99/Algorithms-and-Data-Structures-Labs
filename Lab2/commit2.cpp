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
    size_p2 = 0; 
    size_sum = 0;

 	start = NULL;
    end = NULL;

    start_p2 = NULL; 
    end_p2 = NULL; 

    start_sum = NULL; 
    end_sum = NULL;

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

void Polynomial::coeff_p2(const double coeff_p2[]){ //INDEXING PROBLEM
		cout << "FUNCTION coeff_p2 initialization: " <<'\n'; 
		int i=0; 

		while(coeff_p2[i]!='\0'){ 
    		add_p2coeff_to_list(coeff_p2[i]);
    		i++;
		}
		size_p2 = i; //TODO: The assignment here is broken! Fix this, then take a look at the
		cout << '\n'<<"success, the size is = " << size_p2<< endl<< '\n'; 
}

void Polynomial::get(const Polynomial &expected_polynomial) const  { 
	cout <<"FUNCTION get: " <<'\n';  
	bool Isequal = false;  

	//CASE 1: Compare the size
	if(expected_polynomial.size == this ->size){ 
		for(int i = 0; i < this -> size;i++){  //Reference the start of the expected polynomial specifically 
			if((this->Retrive_nth_node(i, start))==(expected_polynomial.Retrive_nth_node(i, expected_polynomial.start))){ //this you can use ->, else . 
				cout<<"value p1 = "<<this ->Retrive_nth_node(i, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.start)<<endl; 
				Isequal = true; 
				continue;  
			}  else{ 
			cout<<"value p1 = "<<this ->Retrive_nth_node(i, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.start)<<endl; 
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
 			constantvalue = Retrive_nth_node(i, start); 
 			evaluation_value = evaluation_value + constantvalue; 
 			continue;
 		}
 		evaluation_value = evaluation_value + (pow(input, term_value)*(Retrive_nth_node(i, start)));
 		
 	}
 	
 	if(expected_value == evaluation_value ){
 		cout << "success" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 	}

 	else{
 		cout << "failure" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 	}

}

void Polynomial::add(const Polynomial &expected_polynomial) const {
 		cout<<"FUNCTION: add"<<endl;
        Polynomial temp; 
        double sum =0;

        int t_max =0;
        // if degree of right is the largest
        cout<<"p2 size"<<size_p2<<"this size = "<<size<<endl;
	    if ( size_p2 > this->size) {

			 t_max = this->size;

			 temp.size = t_max; 
			

			 for(int i = 0; i < t_max; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, start) + Retrive_nth_node(i, start_p2));
			}

			for(int i = t_max ; i < size_p2 ; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, start_p2));
			}


		}

		else //if degree of this-> is the largest //FIX THIS  ONE AS WELL
		if ( size_p2 <= this->size) {

			 t_max = size_p2 ;
			 temp.size = t_max;
			


			 for(int i = 0; i < t_max; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, start) + Retrive_nth_node(i, start_p2));
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, start));
			}

		}

	//NOW CHECK! 
	bool Isequal = false;  


	//CASE 1: Compare the size
	if(expected_polynomial.size == temp.size){ 
		for(int i = 0; i <  temp.size;i++){  //Reference the start of the expected polynomial specifically 
			if((temp.Retrive_nth_node(i, start))==(expected_polynomial.Retrive_nth_node(i, expected_polynomial.start))){ //this you can use ->, else . 
				cout<<"value p1 = "<<temp.Retrive_nth_node(i, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.start)<<endl; 
				Isequal = true; 
				continue;  
			}  else{ 
			cout<<"value p1 = "<<temp.Retrive_nth_node(i, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.start)<<endl; 
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

void Polynomial::add_p2coeff_to_list(double x){

        Coeff_List *tmp_node = new Coeff_List;
        tmp_node->coeff = x;
        tmp_node->next_coeff = NULL;

        if(start_p2 == NULL)
        {

            start_p2 = tmp_node;
            end_p2 = tmp_node;
           cout<<"start ="<< start_p2 -> coeff<<", ";
        }
        else
        {
            end_p2->next_coeff = tmp_node;
            cout<<"next ="<< end_p2->next_coeff -> coeff<<", ";
            end_p2 = end_p2->next_coeff;
        }

}

void Polynomial::add_temp_coeff_to_list(double x) {

        Coeff_List *tmp_node = new Coeff_List;
        tmp_node->coeff = x;
        tmp_node->next_coeff = NULL;

        if(start_sum == NULL)
        {

            start_sum = tmp_node;
            end_sum = tmp_node;
           cout<<"start ="<< start_sum -> coeff<<", ";
        }
        else
        {
            end_sum->next_coeff = tmp_node;
            cout<<"next ="<< end_sum->next_coeff -> coeff<<", ";
            end_sum = end_sum->next_coeff;
        }

}




double Polynomial::Retrive_nth_node (int index, Coeff_List* start_node) const { //making the sub-functions const to ensure no permanent change
      
    Coeff_List* current_node = start_node;  
     
    for( int i=0; i< size ; i++){
    	if (i == index)  {
            return (current_node-> coeff) ;  
        }
        else{
        	 current_node = current_node-> next_coeff ;  
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

		p6.get(Test1_p); //PROB
		p6.evaluate(2,7.6);

		Polynomial p2; //WHY THIS?!?!
		// double p2_array[] = {1.0,2.2,2.1}; 
		// p6.coeff_p2(p2_array);

		// Polynomial sum_p6_p2;
		// double sum_array[] = {2.0,5.5,2.1}; 
		// sum_p6_p2.coeff_p1(sum_array);


		//p6.add(sum_p6_p2);




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
	int size, size_p2, size_sum;  // degree + 1
    public:
    Coeff_List *start, *end, *start_p2, *end_p2, *start_sum, *end_sum;

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
    void coeff_p2(const double coeff_p2[]); 

    void get(const Polynomial &expected_polynomial) const;
    void evaluate( const double x, const double expected_value) const; 
    void add(const Polynomial &expected_polynomial) const;

   
    Polynomial operator+(const Polynomial& right); 
    void add_coeff_to_list(double x);
    void add_p2coeff_to_list(double x);
    void add_temp_coeff_to_list(double x);
   
    double Retrive_nth_node(int index, Coeff_List* start_node) const;

    // print the polynomial
   // void print();

};
