/*
 * grafo.h
 *
 *  Created on: 14 dic 2016
 *      Author: Paolo
 */

#ifndef GRAFO_H_
#define GRAFO_H_

#include"listaVect.h"


template<class P, class N>
class arco{
	N nodo1;
	N nodo2;
	P peso;
};


template<class E, class P, class N>
class grafo{
public:
	typedef E etichetta;
	typedef P peso;
	typedef N nodo;
	typedef arco<peso, nodo> arco;
	typedef listaVect<nodo*> listaNodi;
	typedef typename listaVect<nodo*>::posizione listaNodiPos;
	typedef listaVect<arco> listaArchi;


	virtual bool vuoto() const = 0;
	virtual void insNodo(nodo&) = 0;
	virtual void insArco(nodo, nodo, peso) = 0;
	virtual void cancNodo(nodo) = 0;
	virtual void cancArco(nodo, nodo) = 0;
	//	virtual bool esisteNodo(Nodo) = 0;
	//	virtual bool esisteArco(Arco) = 0;
	virtual listaNodi adiacenti(nodo) const = 0;
	virtual listaNodi listNodi() const = 0;
	virtual etichetta leggiEtichetta(nodo) const = 0;
	virtual void scriviEtichetta(nodo, etichetta) = 0;
	virtual peso leggiPeso(nodo, nodo) const = 0;
	virtual void scriviPeso(nodo, nodo, peso) = 0;
	virtual int numNodi() = 0;
	virtual int numArchi() = 0;
};

#endif /* GRAFO_H_ */
