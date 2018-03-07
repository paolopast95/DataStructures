/*
 * nodoTreeP.h
 *
 *  Created on: 04 nov 2016
 *      Author: Paolo
 */

#ifndef NODOTREEP_H_
#define NODOTREEP_H_

#include<iostream>
using namespace std;

template<class T>
class nodoTreeP{
public:
	typedef T tipoelem;

	nodoTreeP();
	nodoTreeP(tipoelem);

	nodoTreeP* getGenitore();
	nodoTreeP* getDestro();
	nodoTreeP* getSinistro();
	tipoelem getElemento();
	void setGenitore(nodoTreeP*);
	void setDestro(nodoTreeP*);
	void setSinistro(nodoTreeP*);
	void setElemento(tipoelem);


private:
	nodoTreeP* genitore;
	nodoTreeP* destro;
	nodoTreeP* sinistro;
	tipoelem elemento;
};



template<class T>
nodoTreeP<T>::nodoTreeP()
{
	elemento = 0;
	genitore = NULL;
	destro = NULL;
	sinistro = NULL;
}

template<class T>
nodoTreeP<T>::nodoTreeP(tipoelem x)
{
	elemento = x;
	genitore = NULL;
	sinistro = NULL;
	destro = NULL;
}

template<class T>
nodoTreeP<T>* nodoTreeP<T>::getGenitore()
{
	return genitore;
}

template<class T>
nodoTreeP<T>* nodoTreeP<T>::getDestro()
{
	return destro;
}

template<class T>
nodoTreeP<T>* nodoTreeP<T>::getSinistro()
{
	return sinistro;
}

template<class T>
typename nodoTreeP<T>::tipoelem nodoTreeP<T>::getElemento()
{
	return elemento;
}

template<class T>
void nodoTreeP<T>::setGenitore(nodoTreeP* P)
{
	genitore = P;
}

template<class T>
void nodoTreeP<T>::setDestro(nodoTreeP* D)
{
	destro = D;
}

template<class T>
void nodoTreeP<T>::setSinistro(nodoTreeP* S)
{
	sinistro = S;
}

template<class T>
void nodoTreeP<T>::setElemento(tipoelem E)
{
	elemento = E;
}
#endif /* NODOTREEP_H_ */
