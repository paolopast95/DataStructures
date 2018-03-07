/*
 * BinTreeC.h
 *
 *  Created on: 02 nov 2016
 *      Author: Paolo
 */

#ifndef BINTREEC_H_
#define BINTREEC_H_

#include <iostream>
#include "BinTree.h"
#include "eccezioni.h"

using namespace std;

template<class T>
class binTreec:public binTree<T, int>
{
	static const int NIL = -1;

public:
	typedef typename binTree<T, int>:: tipoelem tipoelem;
	typedef typename binTree<T, int>:: nodo nodo;

	struct _cella{
		nodo genitore;
		nodo sinistro;
		nodo destro;
		tipoelem label;
	};

	typedef struct _cella cella;

	//costruttori e distruttori
	binTreec();
	binTreec(int);
	~binTreec();

	//metodi ereditati dalla classe astratta binTree da implementare
	void create();
	bool isEmpty();
	nodo root();
	nodo parent(nodo);
	nodo sx(nodo);
	nodo dx(nodo);
	bool sxEmpty(nodo);
	bool dxEmpty(nodo);

	tipoelem read(nodo);
	void write(nodo, tipoelem);
	void insRoot();
	void insSx(nodo);
	void insDx(nodo);
	void erase(nodo);

private:
	int MAXLUNG;
	cella *vet;
	int nNodi;
	nodo inizio;
	nodo libera;

};

template<class T>
binTreec<T>::binTreec()
{
	MAXLUNG = 100;
	vet = new cella[MAXLUNG];
	create();
}

template<class T>
binTreec<T>::binTreec(int n)
{
	MAXLUNG = n;
	vet = new cella[MAXLUNG];
	create();
}

template <class T>
binTreec<T>::~binTreec()
{
	erase(inizio);
	delete[] vet;
}

template<class T>
void binTreec<T>::create()
{
	inizio = NIL;
	nNodi = 0;
	for(int i = 0; i < MAXLUNG-1; i++)
	{
		vet[i].sinistro = (i+1)%MAXLUNG;
	}
	vet[MAXLUNG-1].sinistro = NIL;
	libera = 0;
	nNodi = 0;
}

template<class T>
bool binTreec<T>::isEmpty()
{
	if(nNodi == 0)
		return true;
	else
		return false;
}

template<class T>
typename binTreec<T>::nodo binTreec<T>::root()
{
	return inizio;
}

template<class T>
typename binTreec<T>::nodo binTreec<T>::parent(nodo n)
{
	if(n != inizio)
		return vet[n].genitore;
	else
		return n;
}

template<class T>
typename binTreec<T>::nodo binTreec<T>::sx(nodo n)
{
	if(sxEmpty(n) == false)
		return vet[n].sinistro;
	else
		return n;
}

template<class T>
typename binTreec<T>::nodo binTreec<T>::dx(nodo n)
{
	if(dxEmpty(n) == false)
		return vet[n].destro;
	else
		return n;
}

template<class T>
bool binTreec<T>::sxEmpty(nodo n)
{
	if(vet[n].sinistro == NIL)
		return true;
	else
		return false;
}

template<class T>
bool binTreec<T>::dxEmpty(nodo n)
{
	if(vet[n].destro == NIL)
		return true;
	else
		return false;
}

template<class T>
void binTreec<T>::insRoot()
{
	if(inizio == NIL)
	{
		inizio = libera;
		libera = vet[libera].sinistro;
		vet[inizio].sinistro = NIL;
		vet[inizio].destro = NIL;
		vet[inizio].genitore = NIL;
		nNodi++;
	}
	else;
		//inserisci eccezione
}


template<class T>
void binTreec<T>::insSx(nodo n)
{
	nodo q;
	if(isEmpty() == true)
		throw emptyTree();
	else if(n == NIL)
		throw nullNode();
	else if(vet[n].sinistro != NIL)
		throw nodeExists();
	else if(nNodi >= MAXLUNG)
		throw fullSize();
	else
	{
		q = libera;
		libera = vet[libera].sinistro;
		vet[n].sinistro = q;
		vet[q].sinistro = NIL;
		vet[q].genitore = n;
		vet[q].destro = NIL;
		nNodi++;
	}
}

template<class T>
void binTreec<T>::insDx(nodo n)
{
	nodo q;
	if(isEmpty() == true)
		throw emptyTree();
	else if(n == NIL)
		throw nullNode();
	else if(vet[n].destro != NIL)
		throw nodeExists();
	else if(nNodi >= MAXLUNG)
		throw fullSize();
	else
	{
		q = libera;
		libera = vet[libera].sinistro;
		vet[n].destro = q;
		vet[q].genitore = n;
		vet[q].destro = NIL;
		vet[q].sinistro = NIL;
		nNodi++;
	}
}

template<class T>
typename binTreec<T>::tipoelem binTreec<T>::read(nodo n)
{
	if(n != NIL)
	{
		return vet[n].label;
	}
	else
		throw nullNode();
}

template<class T>
void binTreec<T>::write(nodo n, tipoelem x)
{
	if(n != NIL)
		vet[n].label = x;
	else
		throw nullNode();
}

template<class T>
void binTreec<T>::erase(nodo n)
{
	nodo p;
	if(n != NIL)
	{
		if(sxEmpty(n) == false)
			erase(vet[n].sinistro);
		if(dxEmpty(n) == false)
			erase(vet[n].destro);
		if(n != inizio)
		{
			p = parent(n);
			if(vet[p].sinistro == n)
				vet[p].sinistro = NIL;
			else
				vet[p].destro = NIL;
		}
		else
			inizio = NIL;

		nNodi--;
		vet[n].sinistro = libera;
		libera = n;
	}
	else
		throw nullNode();
}


#endif /* BINTREEC_H_ */
