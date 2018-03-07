/*
 * setLista.h
 *
 *  Created on: 23 dic 2016
 *      Author: Paolo
 */

#ifndef SETLISTA_H_
#define SETLISTA_H_
#include<iostream>
#include"set.h"
using namespace std;

template<class T>
class setLista;

template<class T>
class cella
{
	friend class setLista<T>;

private:
	T valore;
	cella<T>* succ;
};



template<class T>
class setLista : public set<T>
{
public:
	typedef typename set<T>::tipoelem tipoelem;
	typedef cella<T>* pos;

	//costruttore e distruttore
	setLista();
	~setLista();


	void create();
	bool emptySet();
	bool isIn(tipoelem);
	void insert(tipoelem);
	void erase(tipoelem);
	void printSet();

	//modifica l'insieme inserendo gli elementi di un altro insieme
	void setUnion(setLista<T>&);
	//modifica l'insieme cancellando gli elementi che non appartengono all'insieme passato come parametro
	void setIntercept(setLista<T>&);
	//modifica l'insieme cancellando gli elementi comuni ai due insiemi
	void setDifference(setLista<T>&);

	//sovraccarico operatore di assegnamento
	setLista<T>& operator=(const setLista<T>&);
private:
	pos begin;
};



template<class T>
setLista<T>::setLista()
{
	begin = NULL;
}


template<class T>
setLista<T>::~setLista()
{
	pos temp;
	while(!emptySet())
	{
		temp = begin;
		begin = begin->succ;
		delete temp;
	}
	delete begin;
}

template<class T>
void setLista<T>::create()
{
	begin = NULL;
}

template<class T>
bool setLista<T>::emptySet()
{
	return (begin == NULL);
}

template<class T>
bool setLista<T>::isIn(tipoelem x)
{
	pos scorri = begin;
	bool trovato = false;
	while(scorri != NULL && !trovato)
	{
		if(scorri->valore == x)
			trovato = true;
		else
			scorri = scorri->succ;
	}
	return trovato;
}

template<class T>
void setLista<T>::insert(tipoelem x)
{
	if(!isIn(x))
	{
		pos temp = new cella<T>;
		temp->valore = x;
		temp->succ = begin;
		begin = temp;
	}
}

template<class T>
void setLista<T>::erase(tipoelem x)
{
	pos pred, scorri, temp;
	scorri = begin;
	if(scorri->valore == x)
	{
		temp = scorri;
		begin = scorri->succ;
		delete temp;
	}
	else
	{
		scorri = scorri->succ;
		pred = begin;
		while(scorri != NULL && scorri->valore != x)
		{
			pred = scorri;
			scorri = scorri->succ;
		}
		if(scorri != NULL)
		{
			temp = scorri;
			pred->succ = scorri->succ;
			delete temp;
		}
	}
}


template<class T>
void setLista<T>::setUnion(setLista<T>& set)
{
	pos corr;
	corr = set.begin;
	while(corr != NULL)
	{
		if(!isIn(corr->valore))
			insert(corr->valore);
		corr = corr->succ;
	}
}


template<class T>
void setLista<T>::setDifference(setLista<T>& set)
{
	pos corr = set.begin;
	while(corr != NULL)
	{
		if(isIn(corr->valore))
			erase(corr->valore);
		corr = corr->succ;
	}
}

template<class T>
void setLista<T>::setIntercept(setLista<T>& set)
{
	pos corr = begin;
	while(corr != NULL)
	{
		if(!set.isIn(corr->valore))
			erase(corr->valore);
		corr = corr->succ;
	}
}

template<class T>
void setLista<T>::printSet()
{
	pos corr = begin;
	while(corr != NULL)
	{
		cout << corr->valore << " ";
		corr = corr->succ;
	}
	cout << endl;
}

template<class T>
setLista<T>& setLista<T>::operator=(const setLista<T>& S)
{
	pos corr = S.begin;
	while(!emptySet())
	{
		corr = begin->succ;
		delete this->begin;
		begin = corr;
	}
	corr = S.begin;
	while(corr != NULL)
	{
		this->insert(corr->valore);
		corr = corr->succ;
	}
	return *this;
}
#endif /* SETLISTA_H_ */
