

//Polynomial& Polynomial::difference(const Polynomial& right) const{

//CASE 1: Same degree 
//Example: 0 + X + 3X^2 and 5 + 6X  + 5X^2 ----- -5 + -5X -2X^2

//CASE 2: Left degree > right degree 
//Example: 0 + X + 3X^2 + 0 + 5X^4 and 5 + 6X + 5X^2 ----- -5 + -5X -2X^2 + 0 + 5X^4 
/*
	idea: subtract coefficients until the size of the smallest array, and then copy the remianing
*/


//CASE 3: Left degree < right degree 
//Example:  5 + 6X + 5X^2 and 0 + X + 3X^2 + 0 + 5X^4 ----- 0 + 5X + 3X^2 + 0 -5X^-4 
/*
	idea: subtract coefficients until the size of the smallest array, and then copy over all the 
	elements of the larger array * -1 
*/

//}

//Polynomial& Polynomial::multiply(const Polynomial& right)const{
/**
// A[] represents coefficients of first polynomial 
// B[] represents coefficients of second polynomial 
// m and n are sizes of A[] and B[] respectively 
int *multiply(int A[], int B[], int m, int n) 
{ 
   int *prod = new int[m+n-1]; 
  
   // Initialize the porduct polynomial 
   for (int i = 0; i<m+n-1; i++) 
     prod[i] = 0; 
  
   // Multiply two polynomials term by term 
  
   // Take ever term of first polynomial 
   for (int i=0; i<m; i++) 
   { 
     // Multiply the current term of first polynomial 
     // with every term of second polynomial. 
     for (int j=0; j<n; j++) 
         prod[i+j] += A[i]*B[j];  //key  is the i is the degree of x and so, you put it at the corresponding prod[degree]
         							// why -> so all the values of the same degree are together. 
   } 
  
   return prod; 
}
***/
//}

//Polynomial Polynomial::derivative(){

/*
Example: 3X^0 + X^1 + 5X^2
Psudo-code: 
	1) multiply the coeff value by the i value 
	2) shift values to the left by 1, replacing the coefficent array and returning the polynomial

*/

//}
