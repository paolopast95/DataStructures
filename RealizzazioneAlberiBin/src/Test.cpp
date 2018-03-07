/*
 * Test.cpp
 *
 *  Created on: 10 nov 2016
 *      Author: Paolo
 */

#include "BinTreeP.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


int main(){
	binTreeP<int> T;
	typename binTreeP<int>::nodo n1, n2;

	T.insRoot();
	T.write(T.root(),1);
	n1 = T.root();
	T.insSx(n1);
	T.insDx(n1);
	T.write(T.sx(n1),2);
	n1 = T.dx(n1);
	T.write(n1, 3);
	T.insDx(n1);
	T.write(T.dx(n1), 4);
	T.print();
	T.erase(n1);
	T.print();
	T.erase(T.root());
	T.print();
	system("PAUSE");
	return 0;
}
