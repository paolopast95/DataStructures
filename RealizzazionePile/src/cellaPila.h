/*
 * cella.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef CELLAPILA_H_
#define CELLAPILA_H_
#include <stdlib.h>


template<class T>
class cella{
public:
	typedef T tipoelem;

	cella();
	cella(tipoelem);
	void setElemento(tipoelem);
	tipoelem getElemento();
	void setSucc(cella*);
	cella* getSucc();

private:
	tipoelem elemento;
	cella* succ;
};

template<class T>
cella<T>::cella()
{
	elemento = 0;
	succ = NULL;
}

template<class T>
cella<T>::cella(tipoelem x)
{
	elemento = x;
	succ = NULL;
}

template<class T>
void cella<T>::setElemento(tipoelem x)
{
	elemento = x;
}

template<class T>
typename cella<T>::tipoelem cella<T>::getElemento()
{
	return elemento;
}

template<class T>
void cella<T>::setSucc(cella<T>* p)
{
	succ = p;
}

template<class T>
cella<T>* cella<T>::getSucc()
{
	return succ;
}

#endif /* CELLAPILA_H_ */
