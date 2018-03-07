/*
 * listaLineare.h
 *
 *  Created on: 21 ott 2016
 *      Author: Paolo
 */

#ifndef LISTALINEARE_H_
#define LISTALINEARE_H_

#include <iostream>
using namespace std;

//creazione della classe astratte listaLineare
template<class T, class P>
class listaLineare{
public:

	//creazione alias
	typedef T tipoelem;
	typedef P posizione;

	//metodi da implementare nelle varie realizzazioni
	virtual void create() = 0;
	virtual bool empty() = 0;
	virtual tipoelem read(posizione) = 0;
	virtual void write(tipoelem, posizione) = 0;
	virtual posizione begin() = 0;
	virtual bool end(posizione) = 0;
	virtual posizione next(posizione) = 0;
	virtual posizione pred(posizione) = 0;
	virtual void insert(tipoelem, posizione&) = 0;
	virtual void erase(posizione&) = 0;

	//metodi da implementare nella classe virtuale
	int size();
	void reverseList();
	bool palindrom();
};

template<class T, class P>
int listaLineare<T, P>::size()
{
	posizione scorri = begin();
	int count = 0;
	while(end(scorri) == false)
	{
		count++;
		scorri = next(scorri);
	}
	return count;
}

template<class T, class P>
void listaLineare<T, P>::reverseList()
{
	posizione sinistra, destra;
	tipoelem temp;

	sinistra = begin();
	destra = begin();
	while(end(next(destra)) == false)
	{
		destra = next(destra);
	}
	while(sinistra != destra && destra != pred(sinistra))
	{
		temp = read(sinistra);
		write(read(destra), sinistra);
		write(temp, destra);
		sinistra = next(sinistra);
		destra = pred(destra);
	}
}

template<class T, class P>
bool listaLineare<T, P>::palindrom()
{
	posizione sinistra, destra;
	bool risultato = true;

	sinistra = begin();
	destra = begin();

	while(end(next(destra)) == false)
	{
		destra = next(destra);
	}

	while(sinistra != destra && destra != pred(sinistra) && risultato == true)
	{
		if(read(sinistra) != read(destra))
		{
			risultato = false;
		}
		sinistra = next(sinistra);
		destra = pred(destra);
	}
	return risultato;
}
#endif /* LISTALINEARE_H_ */
