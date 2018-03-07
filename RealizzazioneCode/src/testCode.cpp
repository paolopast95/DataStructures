/*
 * testCode.cpp
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#include<iostream>
#include "codaPunt.h"
using namespace std;

int main () {
  codaPunt < int > C;

  C.insertQueue (1);
  C.insertQueue (12);
  C.insertQueue(19);
  C.insertQueue (7);
  printQueue(C);
  C.eraseQueue();
  printQueue(C);
  C.insertQueue(0);
  C.insertQueue(11);
  printQueue(C);
  C.eraseQueue();
  printQueue(C);
  C.insertQueue(5);
  C.insertQueue(21);
  C.insertQueue (18);
  printQueue(C);
  C.eraseQueue ();
  printQueue(C);
  C.insertQueue (3);
  printQueue(C);
  C.eraseQueue ();
  printQueue(C);

  system("PAUSE");
  return 0;
}

void printQueue(codaPunt<int>& C)
{
	codaPunt<int>::posizione pos;
	pos = C.testa;
	while(pos != NULL)
	{
		cout << pos->getElemento() << " ";
		pos = pos->getSucc();
	}
	cout << endl;
}
