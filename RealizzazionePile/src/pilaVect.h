/*
 * pilaVect.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */
#ifndef PILAVECT_H_
#define PILAVECT_H_

#include <iostream>
using namespace std;

//realizzazione di pila tramite vettore
template<class T>
class pilaVect
{
public:

	friend void printStack(pilaVect<T>&);
	//definizione alias
	typedef int posizione;
	typedef T tipoelem;

	//costruttore e distruttore
	pilaVect();
	pilaVect(int);
	~pilaVect();

	//metodi
	void createStack();
	bool emptyStack();
	tipoelem readStack();
	void push(tipoelem);
	void pop();


private:
	tipoelem* v;
	int MAXLUNG;
	posizione testa;
};


template<class T>
pilaVect<T>::pilaVect()
{
	MAXLUNG = 20;
	v  = new tipoelem[MAXLUNG];
	testa = 0;
}

template<class T>
pilaVect<T>::pilaVect(int d)
{
	MAXLUNG = d;
	v = new tipoelem[MAXLUNG];
	testa = 0;
}

template<class T>
pilaVect<T>::~pilaVect()
{
	delete[] v;
}

template<class T>
void pilaVect<T>::createStack()
{
	testa = 0;
}

template<class T>
bool pilaVect<T>::emptyStack()
{
	if(testa == 0)
		return true;
	else
		return false;
}

template<class T>
typename pilaVect<T>::tipoelem pilaVect<T>:: readStack()
{
	return v[testa-1];
}

template<class T>
void pilaVect<T>::push(tipoelem x)
{
	if(testa == MAXLUNG)
	{
		cout << "La pila e' piena" << endl;
	}
	else
	{
		v[testa] = x;
		testa++;
	}
}

template<class T>
void pilaVect<T>::pop()
{
	if(emptyStack() == true)
	{
		cout << "La pila e' vuota. Impossibile cancellare!" << endl;
	}
	else
	{
		testa--;
	}
}

#endif /* PILAVECT_H_ */
