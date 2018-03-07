#include <stdlib.h>
#include <iostream>
#include "listavect.h"
#include "listapunt.h"
#include "listaMono.h"
using namespace std;


int main()
{
	listaMono<int> lista, lista2;
	int x;
	listaMono<int>::posizione corr;

	corr = lista.begin();

	x = 1;
	lista.insert(x, corr);

	x = 2;
	lista.insert(x, corr);

	x = 4;
	lista.insert(x, corr);

	corr = lista.next(corr);
	x = 6;
	lista.insert(x, corr);

	lista2 = lista;
	corr = lista.begin();
	lista.erase(corr);

	corr = lista.begin();
	while(lista.end(corr) == false)
	{
		cout << lista.read(corr) << " ";
		corr = lista.next(corr);
	}
	cout << endl;


	corr = lista2.begin();
	while(lista2.end(corr) == false)
	{
		cout << lista2.read(corr) << " ";
		corr = lista2.next(corr);
	}


	system("PAUSE");
	return 0;
}
