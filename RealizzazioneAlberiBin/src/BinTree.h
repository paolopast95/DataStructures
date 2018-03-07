/*
 * BinTree.h
 *
 *  Created on: 02 nov 2016
 *      Author: Paolo
 */

#ifndef BINTREE_H_
#define BINTREE_H_

#include <iostream>
using namespace std;

template<class T, class N>
class binTree{
public:

	static const int NIL = -1;

	typedef T tipoelem;
	typedef N nodo;

	//metodi virtuali da implementare nelle classi concrete
	virtual void create() = 0;
	virtual bool isEmpty() = 0;
	virtual nodo root() = 0;
	virtual nodo parent(nodo) = 0;
	virtual nodo sx(nodo) = 0;
	virtual nodo dx(nodo) = 0;
	virtual bool sxEmpty(nodo) = 0;
	virtual bool dxEmpty(nodo) = 0;

	virtual void erase(nodo) = 0;
	virtual tipoelem read(nodo) = 0;
	virtual void write(nodo, tipoelem) = 0;
	virtual void insRoot() = 0;
	virtual void insSx(nodo) = 0;
	virtual void insDx(nodo) = 0;

	void print();

private:
	void printSub(nodo);
};


template<class T, class N>
void binTree<T, N>::print()
{
	if(isEmpty() == false)
	{
		printSub(root());
	}
	else
	{
		cout << "[]";
	}
	cout << endl;
}

template<class T, class N>
void binTree<T, N>::printSub(nodo P)
{
	cout << "[" << read(P) << ", ";
	if(sxEmpty(P) == false)
	{
		printSub(sx(P));
	}
	else
	{
		cout << "[]";
	}
	cout << ", ";
	if(dxEmpty(P) == false)
	{
		printSub(dx(P));
	}
	else
	{
		cout << "[]";
	}
	cout << "]";
}
#endif /* BINTREE_H_ */
