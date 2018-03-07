/*
 * BinTreeSeq.h
 *
 *  Created on: 10 nov 2016
 *      Author: Paolo
 */

#ifndef BINTREESEQ_H_
#define BINTREESEQ_H_

#include"BinTree.h"

template<class T>
class binTreeSeq : public binTree<T, int>
{
public:

	typedef typename binTree<T, int>::tipoelem tipoelem;
	typedef typename binTree<T, int>::nodo nodo;

	struct _cella{
		bool presente;
		tipoelem label;
	};

	typedef struct _cella cella;

	//costruttori e distruttori
	binTreeSeq();
	binTreeSeq(int);
	~binTreeSeq();

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
};


template<class T>
binTreeSeq<T>::binTreeSeq()
{
	MAXLUNG = 100;
	vet = new cella[MAXLUNG];
	for(int i = 0; i < MAXLUNG; i++)
	{
		vet[i].presente = false;
	}
}

template<class T>
binTreeSeq<T>::binTreeSeq(int dim)
{
	MAXLUNG = dim;
	vet= new cella[MAXLUNG];
	for(int i = 0; i < MAXLUNG; i++)
	{
		vet[i].presente = false;
	}
}

template<class T>
binTreeSeq<T>::~binTreeSeq()
{
	delete[] vet;
}

template<class T>
void binTreeSeq<T>::create()
{
	MAXLUNG = 100;
	vet = new cella[MAXLUNG];
	for(int i = 0; i < MAXLUNG; i++)
	{
		vet[i].presente = false;
	}
}

template<class T>
bool binTreeSeq<T>::isEmpty()
{
	if(vet[0].presente == false)
		return true;
	else
		return false;
}

template<class T>
typename binTreeSeq<T>::nodo binTreeSeq<T>::root()
{
	return 0;
}

template<class T>
typename binTreeSeq<T>::nodo binTreeSeq<T>::parent(nodo n)
{
	return((n-1)/2);
}

template<class T>
typename binTreeSeq<T>::nodo binTreeSeq<T>::sx(nodo n)
{
	return(2*n + 1);
}

template<class T>
typename binTreeSeq<T>::nodo binTreeSeq<T>::dx(nodo n)
{
	return(2*n +2);
}

template<class T>
bool binTreeSeq<T>::sxEmpty(nodo n)
{
	if(vet[sx(n)].presente == false)
		return true;
	else
		return false;
}

template<class T>
bool binTreeSeq<T>::dxEmpty(nodo n)
{
	if(vet[dx(n)].presente == false)
		return true;
	else
		return false;
}

template<class T>
typename binTreeSeq<T>::tipoelem binTreeSeq<T>::read(nodo n)
{
	return vet[n].label;
}

template<class T>
void binTreeSeq<T>::write(nodo n, tipoelem x)
{
	if(vet[n].presente == true)
		vet[n].label = x;
}

template<class T>
void binTreeSeq<T>::insRoot()
{
	vet[0].presente = true;
}

template<class T>
void binTreeSeq<T>::insSx(nodo n)
{
	vet[sx(n)].presente = true;
}

template<class T>
void binTreeSeq<T>::insDx(nodo n)
{
	vet[dx(n)].presente = true;
}

template<class T>
void binTreeSeq<T>::erase(nodo n)
{
	if(sxEmpty(n) == true && dxEmpty(n) == true)
		vet[n].presente = false;
	else
	{
		if(sxEmpty(n) == false)
			erase(sx(n));
		if(dxEmpty(n) == false)
			erase(dx(n));
	}
}
#endif /* BINTREESEQ_H_ */
