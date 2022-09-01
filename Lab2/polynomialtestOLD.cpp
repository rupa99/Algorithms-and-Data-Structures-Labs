// polynomialtest.cpp - implementation file for Polynomial class
// Author: Tiuley Alguindigue (Aug 2019)

#include <iostream>
using namespace std;


#include "Polynomial.h" // class that stores integer polynomials

int main()
{



	    double p1_array[] = {0.0,1.0,3.0};
		Polynomial p1(3,p1_array); // 3 -terms - 0 + X + 3X**2
		p1.print();
		


		double p2_array[] = {1.0,0.0,1.0,2.0};
		Polynomial p2(4,p2_array);  //4-terms  1 + X**2 + 2X**3
		p2.print();


		Polynomial p3; // emptty polynomial
		p3.print();


		Polynomial p1copy(p1); // declaring polynomial with value of p1
		cout << "p1copy   " <<  endl ;
		p1copy.print();




		Polynomial p4;
		p4 = p1.add(p2); // needs = operator
		cout << "p4 after p4 = p1 + p2 " << endl ;
		p4.print();


        // adding with "+"
		Polynomial p5;
		p5 = p1 + p2;
		cout << "p5 after p5 = p1 + p2 " << endl ;
		p5.print();

		// cout<<"Test 1:" <<endl; 
	 //    double Test1_parray[] = {1.0,3.3};
		// Polynomial Test1_p(2,Test1_parray);

		// double p6_array[] = {1.0,3.3};
		// Polynomial p6; 
		// p6.init(2);
		// p6.coeff_p1(p6_array);
		// p6.get(Test1_p); 

		// cout<<"Test 2:" <<endl; 	
		// double p7_array[] = {2.0, 2.0, 3.0};
		// Polynomial p7; 
		// p7.init(3);
		// p7.coeff_p1(p7_array);
		// p7.evaluate(2.0,18.0);


		// cout<<"-------end of tests--------"<<endl;



		/*
		Add here your code to test other methids you implement
		Examples:

		- evaluate  (returns the value of polynomial at given x)
		- derivative (returns the polynomial representing the derivative)
		- diff (you could alternatively overraide "-" )
		- mult  (you could alternatively overraide "*" )


		*/




		return 0;

}
