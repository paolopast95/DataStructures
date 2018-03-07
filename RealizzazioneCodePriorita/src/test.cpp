/*
 * test.cpp
 *
 *  Created on: 17 dic 2016
 *      Author: Paolo
 */
#include"prioriCodaTree.h"
#include<iostream>
#include<stdlib.h>

int main () {
	prioriCodaTree < int > C;

	C.inserisci (1);
	C.inserisci (12);
	C.inserisci (19);
	C.inserisci (7);
	cout << "il minimo e' " << C.min() << endl;
	C.cancellaMin ();
	cout << "il minimo e' " << C.min() << endl;
	C.inserisci (0);
	C.inserisci (11);
	cout << "il minimo e' " << C.min() << endl;
	C.cancellaMin ();
	cout << "il minimo e' " << C.min() << endl;
	C.inserisci (5);
	C.inserisci (21);
	C.inserisci (18);
	cout << "il minimo e' " << C.min() << endl;
	C.cancellaMin ();
	cout << "il minimo e' " << C.min() << endl;
	C.inserisci (3);
	cout << "il minimo e' " << C.min() << endl;
	C.cancellaMin ();
	cout << "il minimo e' " << C.min() << endl;
	system("PAUSE");
	return 0;
}

