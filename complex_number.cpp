#include <iostream>
#include "complex_number.hpp"

using namespace std;
int main ()
{
	complex_number<double> c1 (3.0 , -8.0);
	complex_number<double> c2 (2.0 , 0.0);
	
	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	
	complex_number<double> somma = c1 + c2;
	cout << "Somma: " << c1 + c2 << endl;
	
	complex_number<double> prodotto = c1 * c2 ;
	cout << "Prodotto: " << c1 * c2 << endl;
	
	cout << "Coniugato: " << c1.coniugato() << std :: endl;
	
	
	return 0; 
}