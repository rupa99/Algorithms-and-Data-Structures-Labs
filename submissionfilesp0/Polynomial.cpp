// Polynomial.cpp - implementation file for Polynomial class
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
#include<cmath>
#include <array>
#include <iterator>
#include<cstdlib>
using namespace std;

#include "Polynomial.h"

//UPDATE TO THIS!! 


Polynomial::Polynomial (int x, const double coeff_p[]) {

	size =x; 
 	start = NULL;
    end = NULL;


    for(int i = 0; i < size; i++){
    		add_coeff_to_list(coeff_p[i]);
    		// cout<<"added value ="<<coeff_p[i]<<", i ="<<i<<endl;
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

    start_prod = NULL; 
  	end_prod = NULL;

 }

 // destructor
 Polynomial::~Polynomial() {
 	
 }
 
void Polynomial::init(int m){
	size = m; 
	start = NULL;
    end = NULL;

    start_p2 = NULL; 
    end_p2 = NULL; 

    start_sum = NULL; 
    end_sum = NULL;

    start_prod = NULL; 
  	end_prod = NULL;

	cout<<"success"<<endl;	 
}

void Polynomial::coeff_p1(const Polynomial &current_polynomial)  { //Change: pass in a current polynomial!!!
	// cout << "FUNCTION coeff_p1: "; 

    for(int i = 0; i < size; i++){
    		add_coeff_to_list(current_polynomial.Retrive_nth_node(i, size, current_polynomial.start));
    		
	}
	cout <<"success" <<endl;
	
}

void Polynomial::coeff_p2(int expected_size, const double expected_coeff_p[]) { //Change: pass in a polynomial
	// cout << "FUNCTION coeff_p2 initialization: " <<'\n'; 
	
	Polynomial polynomial_two(expected_size,expected_coeff_p);
	size_p2 = polynomial_two.size;

    for(int i = 0; i < polynomial_two.size; i++){
    		add_p2coeff_to_list(polynomial_two.Retrive_nth_node(i,polynomial_two.size, polynomial_two.start));
	}
	cout <<"success"<< endl;

}

void Polynomial::get(int expected_size, const double expected_coeff_p[]) const{ 

	Polynomial expected_polynomial(expected_size,expected_coeff_p); 


	// cout <<"FUNCTION get: " <<'\n';  
	bool Isequal = false;  

	//CASE 1: Compare the size
	if(expected_polynomial.size == this ->size){ 
		for(int i = 0; i < this -> size;i++){  //Reference the start of the expected polynomial specifically 
			if((this->Retrive_nth_node(i, size, start))==(expected_polynomial.Retrive_nth_node(i, expected_polynomial.size, expected_polynomial.start))){ //this you can use ->, else . 
				// cout<<"value p1 = "<<this ->Retrive_nth_node(i, size, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.size, expected_polynomial.start)<<endl; 
				Isequal = true; 
				continue;  
			}  else{ 
			// cout<<"value p1 = "<<this ->Retrive_nth_node(i,size, start)<<", value p2= "<<expected_polynomial.Retrive_nth_node(i, expected_polynomial.size, expected_polynomial.start)<<endl; 
			Isequal = false;  
			break;
 } 
} 
}

	if(Isequal == true){
		cout << "success"<<endl; 
	}
	else{
		cout << "failure"<< endl; 
	}

}


void Polynomial::evaluate( const double x, const double expected_value) const {
 	// cout << "FUNCTION evaluate: " <<'\n'; 
 	
 	double evaluation_value = 0; 
 	int term_value = 0; 
 	double constantvalue =0; 
 	int input = 0; 

 	input = x; 
 	
 	for(int i = 0; i < size; i++){ 
 		term_value = i; 
 		if(i==0){
 			constantvalue = Retrive_nth_node(i, size, start); 
 			evaluation_value = evaluation_value + constantvalue; 
 			// cout<<"constant value="<<constantvalue;
 			continue;
 		}
 		evaluation_value = evaluation_value + (pow(input, term_value)*(Retrive_nth_node(i,size, start)));
 		
 	}
 	
 	if(expected_value == evaluation_value ){
 		// cout << "success" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 		cout<<"success"<<endl; 
 	}

 	else{
 		// cout << "failure" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
 		cout<<"failure"<<endl;
 	}

}

void Polynomial::add(int expected_size, const double expected_coeff_p[]) const {
 		// cout<<"FUNCTION: add"<<endl;

 		Polynomial expected_polynomial(expected_size,expected_coeff_p);
        Polynomial temp; 
        double sum =0;

        int t_max =0;
        // if degree of right is the largest
       // cout<<"p2 size"<<size_p2<<"this size = "<<size<<endl;

		// cout<<"size_p2 "<<size_p2<<endl;
		// cout<<"size p1 " << this->size<<endl;
	    if ( size_p2 > this->size) {

			 t_max = this->size;

			 temp.size = size_p2; 

			

			 for(int i = 0; i < t_max; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, size, start) + Retrive_nth_node(i, size_p2, start_p2));
			}

			for(int i = t_max ; i < size_p2 ; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, size_p2, start_p2));
			}


		// cout<<"here"<<endl;


		}

		else //if degree of this-> is the largest //FIX THIS  ONE AS WELL
		if ( size_p2 <= this->size) {

			 t_max = size_p2 ;
			 temp.size = this->size;

			 for(int i = 0; i < t_max; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, size, start) + Retrive_nth_node(i, size_p2, start_p2));
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp.add_temp_coeff_to_list(Retrive_nth_node(i, size, start));
			}

		}

	//NOW CHECK! 
	bool Isequal = false;  


	//CASE 1: Compare the size
	// cout<<"exp poly"<<expected_polynomial.size<<endl;
	// cout<<"temp poly"<<temp.size<<endl;
	if(expected_polynomial.size == temp.size){ 
		for(int i = 0; i < temp.size;i++){  //Reference the start of the expected polynomial specifically 
			if((temp.Retrive_nth_node(i, temp.size, temp.start_sum))==(expected_polynomial.Retrive_nth_node(i, expected_polynomial.size, expected_polynomial.start))){ //this you can use ->, else . 
				Isequal = true; 
				continue;  
			}  else{ 
			Isequal = false;  
			break;
 } 
} 
}

	if(Isequal == true){
		cout << "success"<< endl;
	}
	else{
		cout << "failure"<< endl;
	}
		

     

}

void Polynomial::mult(int expected_size, const double expected_coeff_p[]) const {
	// cout<<"FUNCTION: mult"<<endl;
	Polynomial expected_polynomial(expected_size, expected_coeff_p);

    Polynomial temp_mult;

    int TotalSize= size+size_p2-1;

    double *prod = new double[TotalSize]; 
    temp_mult.size = TotalSize;

     for (int i = 0; i<TotalSize; i++) {
    			 prod[i] = 0;  
    }

   	for (int i=0; i<size; i++) { 
     	for (int j=0; j<size_p2; j++) {
         	prod[i+j] += Retrive_nth_node(i, size, start) * Retrive_nth_node(j, size_p2, start_p2); 
     	}
    }

    for(int i=0; i<TotalSize; i++){
         	temp_mult.add_temp_mult_coeff_to_list(prod[i]);
    }


    bool Isequal = false;  

if(expected_polynomial.size == temp_mult.size){ 
		for(int i = 0; i < temp_mult.size;i++){  //Reference the start of the expected polynomial specifically 
			if(abs((temp_mult.Retrive_nth_node(i, temp_mult.size, temp_mult.start_prod))-(expected_polynomial.Retrive_nth_node(i, expected_polynomial.size, expected_polynomial.start)))<0.1){ //this you can use ->, else . 
				Isequal = true; 
				continue;  
			}  else{ 
			Isequal = false;  
			break;
 } 
}
}
if(Isequal == true){
		cout << "success"<< endl;
	}
	else{
		cout << "failure"<< endl;
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
           // cout<<"start ="<< start_p2 -> coeff<<", ";
        }
        else
        {
            end_p2->next_coeff = tmp_node;
            // cout<<"next ="<< end_p2->next_coeff -> coeff<<", ";
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
           // cout<<"start ="<< start_sum -> coeff<<", ";
        }
        else
        {
            end_sum->next_coeff = tmp_node;
            // cout<<"next ="<< end_sum->next_coeff -> coeff<<", ";
            end_sum = end_sum->next_coeff;
        }

}

void Polynomial::add_temp_mult_coeff_to_list(double x) {

        Coeff_List *tmp_node = new Coeff_List;
        tmp_node->coeff = x;
        tmp_node->next_coeff = NULL;

        if(start_prod == NULL)
        {
            start_prod = tmp_node;
            end_prod = tmp_node;
           	// cout<<"start ="<< start_prod -> coeff<<", ";
        }
        else
        {
            end_prod->next_coeff = tmp_node;
            // cout<<"next ="<< end_prod->next_coeff -> coeff<<", ";
            end_prod = end_prod->next_coeff;
        }

}



double Polynomial::Retrive_nth_node (int index, int size_x, Coeff_List* start_node) const { //making the sub-functions const to ensure no permanent change
      
    Coeff_List* current_node = start_node;  
     
    for( int i=0; i< size_x ; i++){
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
