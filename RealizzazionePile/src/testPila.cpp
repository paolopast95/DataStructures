/*
 * testPila.cpp
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */
#include<iostream>
#include<stdlib.h>
#include"pilaPunt.h"

using namespace std;

int main()
{
	pilaPunt<int> P;
	P.push(5);
	P.push(17);
	P.push(70);
	P.push(74);
	printStack(P);
	P.pop();
	printStack(P);
	system("PAUSE");
	return 0;
}

void printStack(pilaPunt<int>& p)
{
	pilaPunt<int>::posizione pos;
	pos = p.top;
	while(pos != NULL)
	{
		cout << pos->getElemento() << " ";
		pos = pos->getSucc();
	}
	cout << endl;
}
