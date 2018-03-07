/*
 * cellaMono.h
 *
 *  Created on: 23 ott 2016
 *      Author: Paolo
 */

#ifndef CELLAMONO_H_
#define CELLAMONO_H_

#include <iostream>
using namespace std;

template<class T>
class cellaMono{
public:
	typedef T tipoelem;

	cellaMono();
	cellaMono(tipoelem);
	void setElemento(tipoelem);
	tipoelem getElemento();
	void setSucc(cellaMono *p);
	cellaMono* getSucc();

private:
	tipoelem elemento;
	cellaMono* succ;
};


template<class T>
cellaMono<T>::cellaMono()
{
	elemento = 0;
	succ = NULL;
}

template<class T>
cellaMono<T>::cellaMono(tipoelem e)
{
	elemento = e;
	succ = NULL;
}

template<class T>
void cellaMono<T>::setElemento(tipoelem e)
{
	elemento = e;
}

template<class T>
typename cellaMono<T>::tipoelem cellaMono<T>::getElemento()
{
	return elemento;
}

template<class T>
void cellaMono<T>::setSucc(cellaMono<T>* p)
{
	succ = p;
}

template<class T>
cellaMono<T>* cellaMono<T>::getSucc()
{
	return succ;
}



#endif /* CELLAMONO_H_ */
