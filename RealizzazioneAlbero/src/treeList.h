/*
 * treeList.h
 *
 *  Created on: 30 nov 2016
 *      Author: Paolo
 */

#ifndef TREELIST_H_
#define TREELIST_H_

#include"tree.h"
#include"listaVect.h"
#include<iostream>
using namespace std;

#define MAXNODES 100

template<class T>
class treeList : public tree<T, int>{

public:
	typedef T tipoelem;
	typedef int node;

	//costruttore
	treeList();
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
	void insFirstSubTree (node, treeList<T> &);
	void insSubTree (node, treeList<T> &);
	void removeSubTree (node) ;
	void writeNode (node, tipoelem) ;
	tipoelem readNode (node);
	void print();

private:
	struct Record {
		tipoelem e;
		bool used;
		listaVect<int> childs;
	};

	typedef listaVect<int>::posizione pos;

	Record nodes[MAXNODES];
	node radice;
	int numNodes;

	//funzione di servizio per copiare un sottoalbero
	void copiaSottoAlbero(node, treeList&, node);

};


template<class T>
treeList<T>::treeList()
{
	create();
}

template<class T>
void treeList<T>::create()
{
	numNodes = 0;
	for(int i = 0; i < MAXNODES; i++)
	{
		nodes[i].used = false;
		nodes[i].childs.create();
	}
}

template<class T>
bool treeList<T>::empty()
{
	return (numNodes == 0);
}

template<class T>
void treeList<T>::insRoot()
{
	radice = 0;
	nodes[0].used = true;
}

template<class T>
typename treeList<T>::node treeList<T>::root()
{
	return radice;
}

template<class T>
typename treeList<T>::node treeList<T>::parent(node N)
{
	pos figlio;
	int p;
	for(int i = 0; i < MAXNODES; i++)
	{
		if(nodes[i].childs.empty() == false)
		{
			figlio = nodes[i].childs.begin();
			bool trovato = false;
			while(nodes[i].childs.end(figlio) == false && trovato == false)
			{
				if(nodes[i].childs.read(figlio) == N)
				{
					trovato = true;
					p = i;
				}
				figlio = nodes[i].childs.next(figlio);
			}
			if(trovato == true)
			return p;
		}

	}
}

template<class T>
bool treeList<T>::leaf(node N)
{
	return(nodes[N].childs.empty());
}

template<class T>
typename treeList<T>::node treeList<T>::firstChild(node N)
{
	if(!leaf(N))
	{
		return nodes[N].childs.read(nodes[N].childs.begin());
	}
}


template<class T>
bool treeList<T>::lastSibling (node N)
{
	if(N == radice)
		return true;
	else
	{
		node p = parent(N);
		pos figlio;
		figlio = nodes[p].childs.begin();
		while(nodes[p].childs.end(nodes[p].childs.next(figlio)) == false)
			figlio = nodes[p].childs.next(figlio);

		return(nodes[p].childs.read(figlio) == N);
	}
}


template<class T>
typename treeList<T>::node treeList<T>::nextSibling (node N)
{
	node p = parent(N);
	pos C;
	C = nodes[p].childs.begin();
	while(nodes[p].childs.end(C) == false)
	{
		if(nodes[p].childs.read(C) == N)
			return nodes[p].childs.read(nodes[p].childs.next(C));
		C = nodes[p].childs.next(C);
	}
}

template<class T>
void treeList<T>::insFirst(node N ,tipoelem el)
{
	node k;
	for(k = 0; k < MAXNODES && nodes[k].used == true; k++);
	if(k < MAXNODES)
	{
		nodes[k].used = true;
		nodes[k].e = el;
		pos inizio = nodes[N].childs.begin();
		nodes[N].childs.insert(k, inizio);
	}
}

template<class T>
void treeList<T>::ins(node N ,tipoelem el)
{
	node k;
	pos C;
	node p;
	for(k = 0; k < MAXNODES && nodes[k].used == true; k++);
	if(k < MAXNODES)
	{
		nodes[k].used = true;
		nodes[k].e = el;
		p = parent(N);
		C = nodes[p].childs.begin();
		while(nodes[p].childs.read(C) != N)
			C = nodes[p].childs.next(C);
		nodes[p].childs.insert(k, C);
	}
}

template<class T>
void treeList<T>::removeSubTree (node N)
{
	pos c;
	if (!leaf(N))
	{
		while (!nodes[N].childs.empty()){
			removeSubTree(nodes[N].childs.read(nodes[N].childs.begin()));
		}
	}
	node p = parent(N);
	c = nodes[p].childs.begin();
	while(nodes[p].childs.read(c) != N)
		c = nodes[p].childs.next(c);
	nodes[p].childs.erase(c);
	nodes[N].used = false;
}

template<class T>
void treeList<T>::writeNode (node N, tipoelem el)
{
	nodes[N].e = el;
}

template<class T>
typename treeList<T>::tipoelem treeList<T>::readNode (node N)
{
	return nodes[N].e;
}


template<class T>
void treeList<T>::print()
{
	cout << "\n{";
	for (int i=0; i < MAXNODES;i++){
		if (nodes[i].used==true){
			cout << "\n  " << readNode(i) << ":  ";
			if (!leaf(i))
			{
				pos child = nodes[i].childs.begin();
				while (!nodes[i].childs.end(child)){
					cout << readNode(nodes[i].childs.read(child)) << " ";
					child = nodes[i].childs.next(child);
				}
			}
		}

	}
	cout << "\n}\n";
}


template<class T>
void treeList<T>::copiaSottoAlbero(node n, treeList& A, node na)
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
void treeList<T>::insFirstSubTree(node n, treeList<T>& A)
{
	this->insFirst(n, 1);
	this->copiaSottoAlbero(this->firstChild(n), A, A.root());
}

template <class T>
void treeList<T>::insSubTree(node n, treeList<T>& A)
{
	if(n != this->root())
	{
		this->ins(n, 0);
		this->copiaSottoAlbero(this->nextSibling(n), A, A.root());
	}
}

//controlla tutta la realizzazione con quella del prof

#endif /* TREELIST_H_ */
