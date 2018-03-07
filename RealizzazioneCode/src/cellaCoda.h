/*
 * cellaCoda.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef CELLACODA_H_
#define CELLACODA_H_

#include <stdlib.h>

template<class T>
class cellaCoda{
public:
	//creazione alias
	typedef T tipoelem;

	//metodi
	cellaCoda();
	cellaCoda(tipoelem);
	void setElemento(tipoelem);
	tipoelem getElemento();
	void setSucc(cellaCoda<T>*);
	cellaCoda<T>* getSucc();

private:
	tipoelem elemento;
	cellaCoda<T>* succ;
};


template<class T>
cellaCoda<T>::cellaCoda()
{
	elemento = 0;
	succ = NULL;
}

template<class T>
cellaCoda<T>::cellaCoda(tipoelem x)
{
	elemento = x;
	succ = NULL;
}

template<class T>
typename cellaCoda<T>::tipoelem cellaCoda<T>::getElemento()
{
	return elemento;
}

template<class T>
void cellaCoda<T>::setElemento(tipoelem x)
{
	elemento = x;
}

template<class T>
cellaCoda<T>* cellaCoda<T>::getSucc()
{
	return succ;
}

template<class T>
void cellaCoda<T>::setSucc(cellaCoda<T>* p)
{
	succ = p;
}
#endif /* CELLACODA_H_ */
