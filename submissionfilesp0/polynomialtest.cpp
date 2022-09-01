// polynomialtest.cpp - Test file  Polynomial class (as array)
// Author: Tiuley Alguindigue (Aug 2019)

//https://www.daniweb.com/programming/software-development/threads/238224/help-to-read-a-txt-file-using-command-line-arguments-in-visual-c

#include <iostream>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//ADD, Mult


using namespace std;

#include "Polynomial.h" // Class to represent polynomials


int main(int argc, char* argv[]){
	string line, word, delimiter; 
	delimiter = ";";
	int p1_size =0; 
	int coeff_p2_size =0; 
	int add_result_size =0; 
	double * coeffp1_array;
	double * get_expected_polynomial;
	double * coeff_p2_polynomial; 
	double * add_result;
	double * mult_result;
	double eval_input =0; 
	double eval_expected_value =0;
	bool prev_is_coeffp1= false;
	int size_of_p1_array=0;


	Polynomial test;


	while(getline(cin, line)){
			word = "";
			// cout<<'\n';

		stringstream singleline(line);

		getline(singleline, word, ' ');

		if(word == "init"){ //PROBLEM!!! FOR INIT2, you didnt initialize!! :( UGH
			// cout<<"Init!"<<endl;
			
			if(prev_is_coeffp1){
				cout<<"success"<<endl;
				prev_is_coeffp1 = false;
				continue;
			}
			
			getline(singleline, word, ' '); 
			p1_size = stoi(word);
			test.init(p1_size);
			// cout<<"the size ="<<p1_size<<endl;
		}

		else if(word == "coeff_p1"){	
			// cout<<"the size ="<<p1_size<<endl;
			coeffp1_array = new double [p1_size];
			// cout<<"coeffp1!"<<endl;

			for(int i=0; i< (p1_size+1); i++){ 

				getline(singleline, word, ' '); 
				if(i==0){
					continue;
				}
				stringstream word1(word);
				string word_segment; 
				if(i!=0 && i!=(p1_size)){
					
						getline(word1, word_segment, ';');
						coeffp1_array[i-1]=stod(word_segment);
						// cout<<"i="<<i<<endl;
						//cout<<"segment= "<<word_segment<<endl;
						continue; 
						}
						// cout<<"i="<<i<<endl;
				coeffp1_array[i-1]=stod(word);	


				//cout<<"word"<<word<<endl;
				}

			Polynomial current_polynomial(p1_size,coeffp1_array);
			test.coeff_p1(current_polynomial);

			// cout<<"print_stmt"<<endl;
			prev_is_coeffp1 = true;
  			// cout<<"after_stmt"<<endl;
			

			}
		
				
				else if(word == "get"){
				prev_is_coeffp1 = false;
				// cout<<"GET"<<endl;
				int i=0;
				int temp_size=0;
				double temp_array[200]; 
				
				while(singleline >> word){
				stringstream word1(word);
				string word_segment; 

				if(i==0){
						++i;
					continue; 
					}
				if(i!=0){
					getline(word1, word_segment, ';');
					temp_array[i-1] =stod(word_segment); 
					//cout<<"segment= "<<word_segment<<endl;
					
				}

				++temp_size;
    			i++;

				}

			
				get_expected_polynomial = new double [temp_size];


				for(int j=0; j<temp_size; j++){

				 	get_expected_polynomial[j] = temp_array[j];
				 	// cout<<"expected array="<< get_expected_polynomial[j]<<endl;
				}

				test.get(temp_size,get_expected_polynomial);
			

			}

					else if(word == "eval"){
				prev_is_coeffp1 = false;
				getline(singleline, word, ' ');
				eval_input = stod(word); 
				getline(singleline, word, ' ');
				eval_expected_value = stod(word);

				// cout<<"eval_input"<<eval_input<<endl;
				// cout<<"eval_expected_value"<<eval_expected_value<<endl;

				test.evaluate(eval_input,eval_expected_value);

			}

				else if(word == "coeff_p2"){
				prev_is_coeffp1 = false;
				// cout<<"coeff_p2"<<endl;
				int i=0;
				int temp_sz=0;
				double temp_arr[200]; 
				

			while(singleline >> word){
				stringstream word1(word);
				string word_segment; 

				if(i==0){
						++i;
					continue; 
					}
				if(i!=0){
					getline(word1, word_segment, ';');
					temp_arr[i-1] =stod(word_segment); 
					// cout<<"segment= "<<word_segment<<endl;
					
				}

				++temp_sz;
    			i++;

				}



				coeff_p2_size = temp_sz;
				coeff_p2_polynomial = new double [coeff_p2_size];


				for(int j=0; j<temp_sz; j++){

				 	coeff_p2_polynomial[j] = temp_arr[j];
				 	//cout<<" "<<endl;
				}

 
	 			test.coeff_p2(coeff_p2_size,coeff_p2_polynomial);

	 			//delete [] coeff_p2_polynomial;

			}

				else if(word =="add"){
				prev_is_coeffp1 = false;
				// cout<<"add"<<endl;
				int i=0;
				int temp_sz=0;
				double temp_arr[200]; 

				while(singleline >> word){
				stringstream word1(word);
				string word_segment; 

				if(i==0){
						++i;
					continue; 
					}
				if(i!=0){
					getline(word1, word_segment, ';');
					temp_arr[i-1] =stod(word_segment); 
					// cout<<"segment= "<<word_segment<<endl;
					
				}

				++temp_sz;
    			i++;

				}

				add_result_size = temp_sz;
				add_result = new double [add_result_size];


				for(int j=0; j<temp_sz; j++){

				 	add_result[j] = temp_arr[j];
				 	// cout<<"add result"<<add_result[j]<<endl;
				}
				test.add(add_result_size,add_result);
			
			}

			else if(word =="mult"){

				prev_is_coeffp1 = false;
				// cout<<"mult"<<endl;
				int i=0;
				int temp_sz=0;
				double temp_arr[200]; 
				while(singleline >> word){
				stringstream word1(word);
				string word_segment; 

				if(i==0){
						++i;
					continue; 
					}
				if(i!=0){
					getline(word1, word_segment, ';');
					temp_arr[i-1] =stod(word_segment); 
					// cout<<"segment= "<<word_segment<<endl;
					
				}

				++temp_sz;
    			i++;

				}
				mult_result = new double [temp_sz];

				i=0;
					// cout<<"temp size= "<<temp_sz<<endl;
				while(i<temp_sz){
					// cout<<"i = "<<i;
					mult_result[i] = temp_arr[i];
					i++;
				}
				test.mult(temp_sz,mult_result);
		}



		}
		return 0;
	}
	
	
			
	
			

			
		

	
	

			

			

		




