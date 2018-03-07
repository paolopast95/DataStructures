/*
 * setOrdLista.h
 *
 *  Created on: 26 dic 2016
 *      Author: Paolo
 */

#ifndef SETORDLISTA_H_
#define SETORDLISTA_H_



#include<iostream>
#include"set.h"
using namespace std;

template<class T>
class setOrdLista;

template<class T>
class cella
{
	friend class setOrdLista<T>;

private:
	T valore;
	cella<T>* succ;
};



template<class T>
class setOrdLista : public set<T>
{
public:
	typedef typename set<T>::tipoelem tipoelem;
	typedef cella<T>* pos;

	//costruttore e distruttore
	setOrdLista();
	~setOrdLista();


	void create();
	bool emptySet();
	bool isIn(tipoelem);
	void insert(tipoelem);
	void erase(tipoelem);
	void printSet();

	//modifica l'insieme inserendo gli elementi di un altro insieme
	void setUnion(setOrdLista<T>&);
	//modifica l'insieme cancellando gli elementi che non appartengono all'insieme passato come parametro
	void setIntercept(setOrdLista<T>&);
	//modifica l'insieme cancellando gli elementi comuni ai due insiemi
	void setDifference(setOrdLista<T>&);

	//sovraccarico operatore di assegnamento
	setOrdLista<T>& operator=(const setOrdLista<T>&);
private:
	pos begin;
};


template<class T>
setOrdLista<T>::setOrdLista()
{
	begin = NULL;
}


template<class T>
setOrdLista<T>::~setOrdLista()
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
void setOrdLista<T>::create()
{
	begin = NULL;
}

template<class T>
bool setOrdLista<T>::emptySet()
{
	return (begin == NULL);
}

template<class T>
bool setOrdLista<T>::isIn(tipoelem x)
{
	pos scorri = begin;
	while(scorri != NULL && scorri->valore < x)
	{
		scorri = scorri->succ;
	}
	if(scorri == NULL)
		return false;
	else
		return (scorri->valore == x);
}

template<class T>
void setOrdLista<T>::insert(tipoelem x)
{
	pos pred = NULL;
	pos scorri = begin;
	if(!isIn(x))
	{
		while(scorri != NULL && scorri->valore < x)
		{
			pred = scorri;
			scorri = scorri->succ;
		}
		pos temp = new cella<T>;
		if(scorri == begin)
		{
			temp->valore = x;
			temp->succ = begin;
			begin = temp;
		}
		else
		{
			temp->valore = x;
			temp->succ = scorri;
			pred->succ = temp;
		}
	}
}

template<class T>
void setOrdLista<T>::erase(tipoelem x)
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
		while(scorri != NULL && scorri->valore < x)
		{
			pred = scorri;
			scorri = scorri->succ;
		}
		if(scorri != NULL && scorri->valore == x)
		{
			temp = scorri;
			pred->succ = scorri->succ;
			delete temp;
		}
	}
}


template<class T>
void setOrdLista<T>::setUnion(setOrdLista<T>& set)
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
void setOrdLista<T>::setDifference(setOrdLista<T>& set)
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
void setOrdLista<T>::setIntercept(setOrdLista<T>& set)
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
void setOrdLista<T>::printSet()
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
setOrdLista<T>& setOrdLista<T>::operator=(const setOrdLista<T>& S)
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
#endif /* SETORDLISTA_H_ */
