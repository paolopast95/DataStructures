/*
 * BinTreeP.h
 *
 *  Created on: 04 nov 2016
 *      Author: Paolo
 */

#ifndef BINTREEP_H_
#define BINTREEP_H_

#include<iostream>
#include"BinTree.h"
#include"nodoTreeP.h"
using namespace std;

template<class T>
class binTreeP : public binTree<T, nodoTreeP<T>*>
{
public:
	typedef typename binTree<T, nodoTreeP<T>*>::tipoelem tipoelem;
	typedef typename binTree<T, nodoTreeP<T>*>::nodo nodo;


	binTreeP();
	~binTreeP();


	void create();
	bool isEmpty();
	nodo root();
	nodo parent(nodo);
	nodo sx(nodo);
	nodo dx(nodo);
	bool sxEmpty(nodo);
	bool dxEmpty(nodo);

	void erase(nodo);
	tipoelem read(nodo);
	void write(nodo, tipoelem);
	void insRoot();
	void insSx(nodo);
	void insDx(nodo);

private:
	nodo radice;
};


template<class T>
binTreeP<T>::binTreeP()
{
	radice = NULL;
}

template<class T>
binTreeP<T>::~binTreeP()
{
	erase(radice);
	delete radice;
}

template<class T>
void binTreeP<T>::create()
{
	radice = NULL;
}

template<class T>
bool binTreeP<T>::isEmpty()
{
	if(radice == NULL)
		return true;
	else
		return false;
}

template<class T>
typename binTreeP<T>::nodo binTreeP<T>::root()
{
	return radice;
}

template<class T>
typename binTreeP<T>::nodo binTreeP<T>::sx(nodo N)
{
	if(sxEmpty(N) == false)
		return N->getSinistro();
	else
		return NULL;
}


template<class T>
typename binTreeP<T>::nodo binTreeP<T>::dx(nodo N)
{
	if(dxEmpty(N) == false)
		return N->getDestro();
	else
		return NULL;
}


template<class T>
typename binTreeP<T>::nodo binTreeP<T>:: parent(nodo N)
{
	if(N != radice)
		return N->getGenitore();
	else
		return NULL;
}

template<class T>
bool binTreeP<T>::sxEmpty(nodo N)
{
	if(N->getSinistro() == NULL)
		return true;
	else
		return false;
}

template<class T>
bool binTreeP<T>::dxEmpty(nodo N)
{
	if(N->getDestro() == NULL)
		return true;
	else
		return false;
}

template <class T>
void binTreeP<T>::insRoot()
{
	nodo temp = new nodoTreeP<T>;

	temp->setGenitore(NULL);
	temp->setSinistro(NULL);
	temp->setDestro(NULL);
	radice = temp;
}

template<class T>
void binTreeP<T>::insDx(nodo N)
{
	nodo temp = new nodoTreeP<T>;
	if(dxEmpty(N) == true && N != NULL)
	{
		temp->setGenitore(N);
		temp->setSinistro(NULL);
		temp->setDestro(NULL);
		N->setDestro(temp);
	}
}

template<class T>
void binTreeP<T>::insSx(nodo N)
{
	nodo temp = new nodoTreeP<T>;
	if(sxEmpty(N) == true && N != NULL)
	{
		temp->setGenitore(N);
		temp->setDestro(NULL);
		temp->setSinistro(NULL);
		N->setSinistro(temp);
	}
}

template<class T>
typename binTreeP<T>::tipoelem binTreeP<T>::read(nodo N)
{
	if(N != NULL)
	{
		return N->getElemento();
	}
}

template<class T>
void binTreeP<T>::write(nodo N, tipoelem x)
{
	if(N != NULL)
	{
		N->setElemento(x);
	}
}


template<class T>
void binTreeP<T>::erase(nodo N)
{
	nodo p;
	if(N != NULL)
	{
		if(sxEmpty(N) == false)
			erase(N->getSinistro());
		if(dxEmpty(N) == false)
			erase(N->getDestro());
		if(N != radice)
		{
			p = N->getGenitore();
			if(p->getSinistro() == N)
			{
				delete p->getSinistro();
				p->setSinistro(NULL);
			}
			else
			{
				delete p->getDestro();
				p->setDestro(NULL);
			}
		}
		else
		{
			delete radice;
			radice = NULL;
		}
	}
}
#endif /* BINTREEP_H_ */
