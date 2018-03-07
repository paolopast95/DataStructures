/*
 * listaPunt.h
 *
 *  Created on: 21 ott 2016
 *      Author: Paolo
 */

#ifndef LISTAPUNT_H_
#define LISTAPUNT_H_

#include "listaLineare.h"
#include "cella.h"

//definizione della classe listaPunt
//listaPunt è la classe di tutte le liste circolari con sentinella!!
template<class T>
class listaPunt : public listaLineare<T, cella<T>*>
{
public:
	//definizione di posizione e tipo dell'elemento
	typedef typename listaLineare<T, cella<T>*>:: posizione posizione;
	typedef typename listaLineare<T, cella<T>*>:: tipoelem tipoelem;

	//costruttori  e distruttori
	listaPunt();
	~listaPunt();
	listaPunt(listaPunt<T>&);

	//metodi
	void create();
	bool empty();
	tipoelem read(posizione);
	void write(tipoelem, posizione);
	posizione begin();
	bool end(posizione);
	posizione next(posizione);
	posizione pred(posizione);
	void insert(tipoelem, posizione&);
	void erase(posizione&);

	//sovraccarico di operatori
	listaPunt<T>& operator=(listaPunt<T>&);
	bool operator==(const listaPunt<T>&);

private:
	posizione lista;
};

template<class T>
listaPunt<T>::listaPunt()
{
	create();
}

template<class T>
listaPunt<T>::listaPunt(listaPunt<T>& l)
{
	tipoelem temp;
	this->lista =(cella<T>*)malloc(sizeof(cella<T>));
	posizione corr = this->begin();
	posizione scorri = l.begin();
	while(l.end(scorri) == false)
	{
		temp = l.read(scorri);
		this->insert(temp, corr);
		scorri = l.next(scorri);
		corr = this->next(corr);
	}
}
template<class T>
listaPunt<T>::~listaPunt()
{
	posizione temp;
	while(lista->getPrec() != lista->getSucc())
	{
		temp = lista->getSucc();
		erase(temp);
	}
	delete lista;
}


template<class T>
void listaPunt<T>::create()
{
	tipoelem elementoNullo = 0;
	lista = (cella<tipoelem>*)malloc(sizeof(cella<tipoelem>));
	lista->setElemento(elementoNullo);
	lista->setPrec(lista);
	lista->setSucc(lista);
}

template<class T>
bool listaPunt<T>::empty()
{
	if(lista->getPrec() == lista && (lista->getSucc() == lista))
		return true;
	else
		return false;
}

template<class T>
typename listaPunt<T>::tipoelem listaPunt<T>:: read(posizione p)
{
	return p->getElemento();
}

template<class T>
void listaPunt<T>::write(tipoelem x, posizione p)
{
	p->setElemento(x);
}

template<class T>
typename listaPunt<T>::posizione listaPunt<T>::begin()
{
	return lista->getSucc();
}

template<class T>
bool listaPunt<T>::end(posizione p)
{
	if(p == lista)
		return true;
	else
		return false;
}

template<class T>
typename listaPunt<T>::posizione listaPunt<T>::next(posizione p)
{
	return p->getSucc();
}

template<class T>
typename listaPunt<T>::posizione listaPunt<T>::pred(posizione p)
{
	return p->getPrec();
}

template<class T>
void listaPunt<T>::insert(tipoelem x, posizione& p)
{
	posizione temp = (cella<tipoelem>*)malloc(sizeof(cella<tipoelem>));
	temp->setElemento(x);
	temp->setPrec(p->getPrec());
	temp->setSucc(p);
	p->getPrec()->setSucc(temp);
	p->setPrec(temp);
	p = temp;
}

template<class T>
void listaPunt<T>::erase(posizione& p)
{
	posizione temp;
	temp = p;
	p->getPrec()->setSucc(p->getSucc());
	p->getSucc()->setPrec(p->getPrec());
	p = p->getSucc();
	delete temp;
}

template<class T>
bool listaPunt<T>::operator==(const listaPunt<T>& l)
{
	posizione pos1, pos2;
	pos1 = this->begin();
	pos2 = l->begin();
	while(this->end(pos1) == false && l->end(pos2) == false)
	{
		if(this->read(pos1) != l->read(pos2))
		{
			return false;
		}
		pos1 = this->next(pos1);
		pos2 = l->next(pos2);
	}

	if(this->end(pos1) == true && l->end(pos2) == true)
	{
		return true;
	}
	else
		return false;

}

template<class T>
listaPunt<T>& listaPunt<T>::operator=(listaPunt<T>& l)
{
	posizione pos, pos2;
	if(this == &l)
	{
		return *this;
	}

	else
	{
		this->~listaPunt();
		this->create();
		pos = begin();
		pos2 = l.begin();
		while(l.end(pos2) == false)
		{
			this->insert(l.read(pos2), pos);
			pos2 = l.next(pos2);
			pos = this->next(pos);
		}
	}
	return *this;
}

#endif /* LISTAPUNT_H_ */
