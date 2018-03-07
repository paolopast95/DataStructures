/*
 * codaCirc.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef CODACIRC_H_
#define CODACIRC_H_

#include "codaClasseAstratta.h"
#include <iostream>
using namespace std;

template<class T>
class codaCirc : public coda<T, int>
{
public:
	//funzione friend che avrà accesso alla parte privata della classe
	friend void printQueue(codaCirc&);

	//creazione di alias per posizione e tipoelem
	typedef typename coda<T, int>::posizione posizione;
	typedef typename coda<T, int>::tipoelem tipoelem;

	//costruttore e distruttore
	codaCirc();
	codaCirc(int);
	~codaCirc();

	//metodi
	void createQueue();
	bool emptyQueue();
	tipoelem readQueue();
	void insertQueue(tipoelem);
	void eraseQueue();

private:
	tipoelem* v;
	int testa;
	int dimensione;
	int lunghezza;
};


template<class T>
codaCirc<T>::codaCirc()
{
	dimensione = 20;
	v = new tipoelem [dimensione];
	lunghezza = 0;
	testa = 0;
}

template<class T>
codaCirc<T>::codaCirc(int d)
{
	dimensione = d;
	v = new tipoelem[dimensione];
	lunghezza = 0;
	testa = 0;
}

template<class T>
codaCirc<T>::~codaCirc()
{
	delete[] v;
}

template<class T>
void codaCirc<T>::createQueue()
{
	dimensione = 20;
	v = new tipoelem[dimensione];
	lunghezza = 0;
	testa = 0;
}

template <class T>
bool codaCirc<T>::emptyQueue()
{
	if(lunghezza == 0)
		return true;
	else
		return false;
}

template<class T>
typename codaCirc<T>::tipoelem codaCirc<T>::readQueue()
{
	if(emptyQueue() == false)
		return v[testa];
	else
		cout << "La pila e' vuota"<< endl;
}

template<class T>
void codaCirc<T>::insertQueue(tipoelem x)
{
	if(lunghezza != dimensione)
	{
		v[(testa+lunghezza)%dimensione] = x;
		lunghezza++;
	}
}

template<class T>
void codaCirc<T>::eraseQueue()
{
	if(emptyQueue() == false)
	{
		testa = (testa+1)%dimensione;
		lunghezza--;
	}
	else
	{
		cout << "La coda e' vuota! Impossibile cancellare" << endl;
	}
}

#endif /* CODACIRC_H_ */
