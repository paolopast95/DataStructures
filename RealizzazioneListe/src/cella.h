/*
 * cella.h
 *
 *  Created on: 21 ott 2016
 *      Author: Paolo
 */

#ifndef CELLA_H_
#define CELLA_H_

#include <iostream>
using namespace std;

template<class T>
class cella
{
public:
	typedef T tipoelem;

	cella();
	cella(tipoelem e);
	void setElemento(tipoelem e);
	tipoelem getElemento();
	void setSucc(cella *p);
	cella* getSucc() {return succ;}
	void setPrec(cella *p);
	cella* getPrec() {return prec;}
private:
	tipoelem elemento;
	cella* prec;
	cella* succ;
};


template<class T>
cella<T>::cella(tipoelem e)
{
	prec = NULL;
	succ = NULL;
	elemento = e;
}

template<class T>
void cella<T>::setElemento(tipoelem e)
{
	elemento = e;
}

template<class T>
typename cella<T>::tipoelem cella<T>::getElemento()
{
	return elemento;
}

template<class T>
void cella<T>::setSucc(cella* p)
{
	succ = p;
}


template<class T>
void cella<T>::setPrec(cella* p)
{
	prec = p;
}
#endif /* CELLA_H_ */
