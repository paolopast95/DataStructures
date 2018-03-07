/*
 * test.cpp
 *
 *  Created on: 24 dic 2016
 *      Author: Paolo
 */



#include"setOrdLista.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	setOrdLista<int> set1, set2, temp;
	set1.insert(2);
	set1.insert(9);
	set1.insert(10);
	set1.insert(4);
	set1.insert(-1);
	set1.insert(99);
	set1.insert(99);
	set1.insert(85);
	set1.printSet();
	set1.erase(2);
	cout << "Primo insieme\n";
	set1.printSet();

	set2.insert(14);
	set2.insert(5);
	set2.insert(10);
	set2.insert(73);
	set2.insert(22);
	set2.insert(99);
	cout << "Secondo insieme\n";
	set2.printSet();
	temp = set1;

	set1.setUnion(set2);
	cout << "Unione dei due insiemi\n";
	set1.printSet();

	set1 = temp;
	set1.setDifference(set2);
	cout << "Differenza fra il primo e il secondo\n";
	set1.printSet();

	set1 = temp;
	set1.setIntercept(set2);
	cout << "Intersezione tra i due insiemi\n";
	set1.printSet();
	system("PAUSE");
	return 0;
}
