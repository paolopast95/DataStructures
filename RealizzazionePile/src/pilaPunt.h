/*
 * pilaPunt.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef PILAPUNT_H_
#define PILAPUNT_H_

#include "pilaClasseAstratta.h"
#include "cellaPila.h"

template<class T>
class pilaPunt : public pila<T, cella<T>*>
{
public:
	//funzione friend che avrà accesso alla parte privata della classe
	friend void printStack(pilaPunt<T>&);

	//creazione degli alias
	typedef typename pila<T, cella<T>*>::posizione posizione;
	typedef typename pila<T, cella<T>*>::tipoelem tipoelem;

	//costruttore e distruttore
	pilaPunt();
	~pilaPunt();

	//metodi
	void createStack();
	bool emptyStack();
	tipoelem readStack();
	void push(tipoelem);
	void pop();

private:
	posizione top;
};


template<class T>
pilaPunt<T>::pilaPunt()
{
	top = NULL;
}

template<class T>
pilaPunt<T>::~pilaPunt()
{
	while(emptyStack() == false)
	{
		pop();
	}
	delete top;
}

template<class T>
void pilaPunt<T>::createStack()
{
	top =  NULL;
}

template<class T>
bool pilaPunt<T>::emptyStack()
{
	if(top == NULL)
		return true;
	else
		return false;
}


template<class T>
typename pilaPunt<T>::tipoelem pilaPunt<T>::readStack()
{
	return top->getElemento();
}

template<class T>
void pilaPunt<T>::push(tipoelem x)
{
	posizione temp;
	temp = new cella<T>;
	temp->setElemento(x);
	temp->setSucc(top);
	top = temp;
}

template<class T>
void pilaPunt<T>::pop()
{
	posizione temp;
	temp = top;
	top = top->getSucc();
	delete temp;
}
#endif /* PILAPUNT_H_ */
