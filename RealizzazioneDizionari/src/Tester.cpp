/*
 * Tester.cpp
 *
 *  Created on: 23 nov 2016
 *      Author: Paolo
 */

#include"tavolaHashTrabocco.h"
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
	char c;
	coppia<string, int> cp;
	coppia<string, int> *appartenenza;
	string chiave;
	tavolaHashTrabocco<string, int> dictionary;
	cout << "Inserisci 3 elementi nel dizionario\n";
	for(int i = 0; i < 3; i++)
	{
		cout << "Inserisci la chiave del " << i+1 <<"o elemento-> ";
		cin >> cp.chiave;
		cout <<"Inserisci il valore associato-> ";
		cin >> cp.valore;
		dictionary.insert(cp);
		cout << endl;
	}

	cout <<"Inserisci una chiave presente nel dizionario: ";
	cin >> chiave;
	appartenenza = dictionary.find(chiave);
	if(appartenenza == NULL)
		cout << "Elemento non presente!\n";
	else
		cout <<"Il valore associato alla chiave e' " << appartenenza->valore << endl;

	cout <<"Inserisci una chiave non presente nel dizionario: ";
	cin >> chiave;
	appartenenza = dictionary.find(chiave);
	if(appartenenza == NULL)
		cout << "Elemento non presente!\n";
	else
		cout <<"Il valore associato alla chiave e' " << appartenenza->valore << endl;

	cout << "Inserisci la chiave di un elemento da cancellare-> ";
	cin >> chiave;
	dictionary.erase(chiave);
	cout <<"Inserisci la chiave dell'elemento appena cancellato dal dizionario: ";
	cin >> chiave;
	appartenenza = dictionary.find(chiave);
	if(appartenenza == NULL)
		cout << "Elemento non presente!\n";
	else
		cout <<"Il valore associato alla chiave e' " << appartenenza->valore << endl;
	cin>>c;
	return 0;
}

