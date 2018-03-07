/*
 * codaPunt.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef CODAPUNT_H_
#define CODAPUNT_H_

#include<iostream>
#include"codaClasseAstratta.h"
#include"cellaCoda.h"

template<class T>
class codaPunt : public coda<T, cellaCoda<T>*>
{
public:
	//funzione friend che ha accesso agli attributi privati della classe
	friend void printQueue(codaPunt<T>&);

	//creazione di alias
	typedef typename coda<T, cellaCoda<T>*>::posizione posizione;
	typedef typename coda<T, cellaCoda<T>*>::tipoelem tipoelem;

	//costruttore e distruttore
	codaPunt();
	~codaPunt();

	//metodi
	void createQueue();
	bool emptyQueue();
	tipoelem readQueue();
	void insertQueue(tipoelem);
	void eraseQueue();

private:
	posizione testa;
	posizione coda;
};


template<class T>
codaPunt<T>::codaPunt()
{
	testa = NULL;
	coda = NULL;
}

template<class T>
codaPunt<T>::~codaPunt()
{
	while(emptyQueue()==false)
	{
		eraseQueue();
	}
	delete testa;
	delete coda;
}

template<class T>
void codaPunt<T>::createQueue()
{
	testa = NULL;
	coda = NULL;
}

template<class T>
bool codaPunt<T>::emptyQueue()
{
	if(testa == NULL)
		return true;
	else
		return false;
}

template<class T>
typename codaPunt<T>::tipoelem codaPunt<T>::readQueue()
{
	return testa->getElemento();
}

template<class T>
void codaPunt<T>::insertQueue(tipoelem x)
{
	posizione temp;
	temp = new cellaCoda<T>;
	temp->setElemento(x);
	temp->setSucc(NULL);
	if(testa == NULL)
	{
		testa = temp;
	}
	else
	{
		coda->setSucc(temp);
	}
	coda = temp;
}

template<class T>
void codaPunt<T>::eraseQueue()
{
	posizione temp;
	if(emptyQueue() == false)
	{
		temp = testa;
		testa = testa->getSucc();
		delete temp;
	}
}
#endif /* CODAPUNT_H_ */
