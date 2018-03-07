/*
 * treeP.h
 *
 *  Created on: 30 nov 2016
 *      Author: Paolo
 */

#ifndef TREEP_H_
#define TREEP_H_

#include <iostream>
#include"tree.h"
using namespace std;

template<class T>
class treeP;


template< class T >
class cella{
	friend class treeP<T>;
private:
	cella<T>* genitore;
	cella<T>* primoFiglio;
	cella<T>* succFratello;
	T elemento;
};


template<class T>
class treeP : public tree< T, cella<T>* >
{

public:
	typedef T tipoelem;
	typedef cella<T>* node;

	//costruttore
	treeP();
	//metodi
	void create () ;
	bool empty ();
	void insRoot () ;
	node root ();
	node parent (node);
	bool leaf (node);
	node firstChild (node);
	bool lastSibling (node);
	node nextSibling (node);
	void insFirst(node,tipoelem);
	void ins(node, tipoelem);
	void insFirstSubTree (node, treeP<T> &);
	void insSubTree (node, treeP<T> &);
	void removeSubTree (node) ;
	void writeNode (node, tipoelem) ;
	tipoelem readNode (node);
	void print();
	//funzione di servizio
	void printSubTree(node);

private:
	void copiaSottoAlbero(node, treeP<T>&, node);
	cella<T>* radice;
};


template<class T>
treeP<T>::treeP()
{
	create();
}

template<class T>
void treeP<T>::create ()
{
	radice = NULL;
}

template<class T>
bool treeP<T>::empty ()
{
	return(radice == NULL);
}

template<class T>
void treeP<T>::insRoot ()
{
	cella<T>* temp = (cella<T>*)new cella<T>;
	temp->primoFiglio = NULL;
	temp->genitore = NULL;
	temp->succFratello = temp;
	radice = temp;
}

template<class T>
typename treeP<T>::node treeP<T>::root()
{
	return radice;
}


template<class T>
typename treeP<T>::node treeP<T>::parent (node N)
{
	if(N != root())
		return N->genitore;
	else
		return NULL;
}

template<class T>
bool treeP<T>::leaf (node N)
{
	return (N->primoFiglio == NULL);
}

template<class T>
typename treeP<T>::node treeP<T>::firstChild (node N)
{
	return N->primoFiglio;
}

template<class T>
bool treeP<T>::lastSibling (node N)
{
 	return(N->succFratello == NULL);
}

template<class T>
typename treeP<T>::node treeP<T>::nextSibling (node N)
{
	return N->succFratello;
}

template<class T>
void treeP<T>::insFirst(node N,tipoelem el)
{
	cella<T>* temp = new cella<T>;
	temp->elemento = el;
	temp->genitore = N;
	temp->primoFiglio = NULL;
	temp->succFratello = N->primoFiglio;
	N->primoFiglio = temp;
}

template<class T>
void treeP<T>::ins(node N, tipoelem el)
{
	cella<T>* temp = new cella<T>;
	temp->elemento = el;
	temp->genitore = N->genitore;
	temp->primoFiglio = NULL;
	temp->succFratello = N->succFratello;
	N->succFratello = temp;
}

template<class T>
void treeP<T>::removeSubTree(node N)
{
	node corr;
	corr = N;
	if(leaf(N) == true)
	{
		node p, scorri;
		p = parent(N);
		scorri = p->primoFiglio;
		if(scorri == N)
		{
			p->primoFiglio = scorri->succFratello;
			delete scorri;
		}
		else
		{
			while(scorri->succFratello != N)
			{
				scorri = scorri->succFratello;
			}
			node temp;
			temp = scorri->succFratello;
			scorri->succFratello = temp->succFratello;
			delete temp;
		}
	}
	else
	{
		corr = N->primoFiglio;
		while(this->lastSibling(corr) == false)
		{
			removeSubTree(corr);
			corr = corr->succFratello;
		}
		removeSubTree(corr);

		node p, scorri;
		p = parent(N);
		scorri = p->primoFiglio;
		if(scorri == N)
		{
			p->primoFiglio = scorri->succFratello;
			delete scorri;
		}
		else
		{
			while(scorri->succFratello != N)
			{
				scorri = scorri->succFratello;
			}
			node temp;
			temp = scorri->succFratello;
			scorri->succFratello = temp->succFratello;
			delete temp;
		}
	}
}

template<class T>
void treeP<T>::writeNode (node N, tipoelem el)
{
	N->elemento = el;
}

template<class T>
typename treeP<T>::tipoelem treeP<T>::readNode (node N)
{
	return N->elemento;
}

template<class T>
void treeP<T>::print()
{
	printSubTree(radice);
	cout << endl;
}

template<class T>
void treeP<T>::printSubTree(node N)
{
	node corr;
	cout << N->elemento << " ";
	if(leaf(N) == false)
	{
		corr = this->firstChild(N);
		while(this->lastSibling(corr) == false)
		{
			this->printSubTree(corr);
			corr = this->nextSibling(corr);
		}
		this->printSubTree(corr);
	}
}


template<class T>
void treeP<T>::copiaSottoAlbero(node n, treeP<T>& A, node na)
{
	node scorri = na;
	node copia = n;
	this->writeNode(copia, A.readNode(scorri));
	if(!A.leaf(scorri))
	{
		scorri = A.firstChild(scorri);
		this->insFirst(copia, 0);
		copia = this->firstChild(copia);
		copiaSottoAlbero(copia, A, scorri);
		while(!A.lastSibling(scorri))
		{
			scorri = A.nextSibling(scorri);
			this->ins(copia, 0);
			copia = this->nextSibling(copia);
			copiaSottoAlbero(copia, A, scorri);
		}
	}
}


template <class T>
void treeP<T>::insFirstSubTree(node n, treeP<T>& A)
{
	this->insFirst(n, 1);
	this->copiaSottoAlbero(this->firstChild(n), A, A.root());
}

template <class T>
void treeP<T>::insSubTree(node n, treeP<T>& A)
{
	if(n != this->root())
	{
		this->ins(n, 0);
		this->copiaSottoAlbero(this->nextSibling(n), A, A.root());
	}
}

#endif /* TREEP_H_ */
