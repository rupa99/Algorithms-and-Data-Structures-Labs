// Polynomial.cpp - implementation file for Polynomial clas
// Author: Tiuley Alguindigue (Aug 2019)


#include <iostream>
#include <cmath>
using namespace std;

#include "Polynomial.h" //calling the header file 

//Q: When to put a pointer reference and when to not? 
//Q: What does the const mean at the end? 

Polynomial::Polynomial (const int& size_p, const double coeff_p[]) {
 	size= size_p;
 	node *coeff_list = new node; //TODO: Change the name 

    for(int i = 0; i < size_p; i++){
    	add_coeff(coeff_p[i]); //transferring the array
	}

 }

 Polynomial::Polynomial() { //assigning default values for the constructor 
 	coeff_list = 0;
 	size = 0;

 	head = NULL;
    tail = NULL;
 

 }


 // copy constructor and equal operator
 /* Copies elements from the right into the left or the "this" one*/
Polynomial::Polynomial (const Polynomial &polynomial_to_copy){
	this->size = polynomial_to_copy.size ; //"this"- Is the polynomial on the left.  
	node *coeff_list = new node; 


	for(int i = 0; i < size; i++){
    	add_coeff(polynomial_to_copy.retrive_coeff(head, i));
	}

}


 // destructor
 Polynomial::~Polynomial() {
 	delete [] coeff_list ; // delete array that starts at address stored in coeff
 }

//
// assignment operator that is exception safe - uses the copy-swap idiom
Polynomial& Polynomial::operator=(const Polynomial& other) // copy assignment
{
	// make a copy of the right hand side
	Polynomial temp(other); //copy constructor- object calld temp with the class name polynomial 

	//Now, swap the data members with the temporary
	std::swap(size,temp.size); //swaps values with the temporary, so the actual one for the other is not changed 
	std::swap(coeff_list,temp.coeff_list);

	return *this ; //returns the new size and coeff properties of the "this" polynomial 

}


Polynomial Polynomial::add( const Polynomial& right) const {
	 	int temp_size = max(this->size,right.size); //gets the maximum of the sizes

        double *temp = new double[temp_size]; // allocate temp array

        int t_max ;
        //itterates through the larger set size 
        // if degree of right is the largest
	    if ( right.size > this->size) { 

			 t_max = this->size;
			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff_list.retrive_coeff(head, i) + right.retrive_coeff(head, i);
			}

			for(int i = t_max ; i < right.size ; i++){
	    		temp[i] = right.coeff_list.retrive_coeff(head, i) ;
			}

		}

		else //if degree of this-> is the largest
		if ( right.size <= this->size) {

			 t_max = right.size ;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff_list.retrive_coeff(head, i) + right.coeff_list.retrive_coeff(head, i);
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp[i] = this -> coeff_list.retrive_coeff(head, i) ;
			}

		}


        Polynomial p(temp_size,temp) ;

        delete [] temp; // delete temp array

        return p;

	}

	Polynomial Polynomial::operator+(const Polynomial& right) {
		int temp_size = max(this->size,right.size);

        double *temp = new double[temp_size]; // allocate temp array

        int t_max ;
        // if degree of right is the largest
	    if ( right.size > this->size) {

			 t_max = this->size;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff_list.retrive_coeff(head, i) + right.coeff_list.retrive_coeff(head, i);
			}
// Polynomial.cpp - implementation file for Polynomial clas
// Author: Tiuley Alguindigue (Aug 2019)

			for(int i = t_max ; i < right.size ; i++){
	    		temp[i] = right.coeff_list.retrive_coeff(head, i) ;
			}


		}

		else //if degree of this-> is the largest
		if ( right.size <= this->size) {

			 t_max = right.size ;


			 for(int i = 0; i < t_max; i++){
	    		temp[i] = this->coeff_list.retrive_coeff(head, i) + right.coeff_list.retrive_coeff(head, i);
			}

			for(int i = t_max; i < this ->size ; i++){
	    		temp[i] = this -> coeff_list.retrive_coeff(head, i);
			}

		}


        Polynomial p(temp_size,temp) ;

        delete [] temp; // delete temp array

        return p;


	}



 void Polynomial::print(){
    for(int i = 0; i < size; i++){
    	cout << coeff_list.retrive_coeff(head, i) << " ";
	}

	cout << endl ;
}

void add_coeff(const double x) const{ //TODO: FIX UP!!! 
	
        coeff_list->data = x;
        coeff_list->next = NULL;	

        if(head == NULL)
        {
            head = coeff_list;
            tail = coeff_list;
        }
        else
        {
            tail->next = coeff_list;
            tail = tail->next;
        }
}

double retrive_coeff(Polynomial::node* head, int index)  
{  
      
    node* current = head;  
      
    // the index of the  
    // node we're currently  
    // looking at  
    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
        
}  

// void Polynomial::init(int m){
// 	size = m; 
// 	cout << "FUNCTION init: " <<'\n'<< "success "<<"expected m = "<<m<< " , actual size is = "<< size << endl << '\n';  
	 
// }

// void Polynomial::coeff_p1(const double coeff_p1[]){
// 	cout << "FUNCTION coeff_p1: " <<'\n'; 
// 	coeff = new double[size];

//     for(int i = 0; i < size; i++){
//     		coeff[i] = coeff_p1[i]; //transferring the array
//     		cout << "actual = " << coeff[i] << ", expected = " << coeff_p1[i] << endl; 
// 	}

// 	cout << "success" << endl<< '\n'; 

// }

// void Polynomial::get(const Polynomial &expected_polynomial) const {
// 	cout << "FUNCTION get: " <<'\n'; 
// 	bool Isequal = false; 
// //CASE 1: Compare the size 
// 	if(expected_polynomial.size == this ->size){
//  		for(int i = 0; i < this -> size; i++){
//     		if(coeff[i] = expected_polynomial.coeff[i]){
//     			Isequal = true; 
//     			continue; 
//     		} 
//     		else{
//     			Isequal = false; 
//     			break; 
//     		}
// 		}
// 	}

// 	//CHECK 
// 	if(Isequal == true){
// 		cout << "success" << " the polynomials are equal" << endl << '\n'; 
// 	}
// 	else{
// 		cout << "failure" << "the polynomials are not equal" << endl <<'\n';  
// 	}


// }



//  void Polynomial::evaluate( const double x, const double expected_value) const {
//  	cout << "FUNCTION evaluate: " <<'\n'; 
//  	/*Psudo: 
//  		- declare evaluation. 
//  		- declare value of the term. 
// 		for (all the values in the coeff array){
// 			evaluation = evaluation +x^(index+1)(coeff at the index)

// 		}
//  	*/
//  	int evaluation_value = 0; 
//  	int term_value = 0; 
//  	int constantvalue =0; 
//  	int input = 0; 

//  	input = x; 
 	
//  	for(int i = 0; i < size; i++){ 
//  		term_value = i; 
//  		if(i==0){
//  			constantvalue = coeff[i]; 
//  			evaluation_value = evaluation_value + constantvalue; 
//  			continue;
//  		}
//  		evaluation_value = evaluation_value + (pow(input, term_value)*(coeff[i]));
 		
//  	}
 	
//  	if(expected_value == evaluation_value ){
//  		cout << "success" << "the expected value = " << expected_value << " the evaluation value = " << evaluation_value <<endl<<'\n'; 
//  	}

// }

// void Polynomial::coeff_p2(const Polynomial &expected_polynomial) const {


// }









