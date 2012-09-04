#include <cstdlib>
#include <iostream>
#include "neljas.h"

using namespace std;

int main (int argc, char* argv[]) {

	// Task 1: swapping
	double a = 1.0, b = -2.0, c = 1.0;
	swap_ref<double> (a, b);
	swap_ptr<double> (&a, &b);

	// Task 2: equation
	double solution1 = 0, solution2 = 0;	// lahendused võiksid olla 1 ja 1
	if (solve (a, b, c, solution1, solution2)) {
		cout << "Solutions are: " << solution1 << ", " << solution2 << endl;
	} else {
		cout << "There are no solutions in real numbers!" << endl;	
	}

	// Task 3
	Vector2 p1 (1.0, 2.0); Vector2 p2 (0,0); Vector2 p3 (5.0, 2.0);
	DynamicLine<Vector2> l1 (&p1, &p2);	// lõik p1 ja p2 vahel
	DynamicLine<Vector2> l2 = l1;		// kopeerime lõigu l1 (tipud jäävad samaks)
	l2.p2 = &p3;				// määrame l2 teise otstipu
	p1.x = 2.0;		

	// Task 4
	MyArray<int> numbers;			// jada arvudest
	numbers.addElement (5);			// lisame ühe elemendi
	numbers.addElement (11);		// ja veel ühe
	MyArray<int> copy = numbers;		// kopeerime jada
	copy.addElement (13);			// lisame koopiasse elemendi
	if (numbers.getSize () != 2 || copy.getSize () != 3)	// kontrollime suuruseid 
		cout << "Copy failed – wrong sizes!" << endl;
	if (numbers[0] != copy[0] || numbers[1] != copy[1]) // kontrollime sisu
		cout << "Copy failed – wrong elements!" << endl;

	return EXIT_SUCCESS;
}
