//============================================================================
// Name        : 06_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : class in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include "point.h"


using namespace std;

void Point::afficher() {
	printf("%d, %d\n", x, y);
}
void Point::positionner(int X, int Y) {
	x = X;
	y = Y;
}

int main() {
//	cout << "Hello World" << endl; // prints Hello World

//	Chaine* chaines;
//	chaines = new Chaine[10];
	Chaine s(20);
	char ch[] = "abcdefg";
	s.affecter(ch, 7);
	s.afficher();
	Chaine r;
	Chaine x = s;	// initialisation de x avec s
	x.afficher();
	r = s;			// recopie s dans r
	r.afficher();
	return 0;
}
