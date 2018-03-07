/*
 * listaVect.h
 *
 *  Created on: 21 ott 2016
 *      Author: Paolo
 */

#ifndef LISTAVECT_H_
#define LISTAVECT_H_

#include "listaLineare.h"

//definizione della classe listaVect
//listaVect è l'insieme di tutte le liste realizzate con vettore
template<class T>
class listaVect : public listaLineare<T, int>
{
public:
	//definizione di posizione e tipo dell'elemento
	typedef typename listaLineare<T, int>:: posizione posizione;
	typedef typename listaLineare<T, int>:: tipoelem tipoelem;

	//costruttori  e distruttori
	listaVect();
	listaVect(int);
	~listaVect();
	listaVect(const listaVect<T>&);

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
	listaVect<T>& operator=(const listaVect<T>&);
	bool operator==(const listaVect<T> &);

private:
	void change_dimension(T*& , int , int );
	tipoelem *v;
	int lunghezza;
	int dimensione;
};


template<class T>
listaVect<T>::listaVect()
{
	lunghezza = 0;
	dimensione = 10;
	v = new T[dimensione];
}

template<class T>
listaVect<T>::listaVect(int dim)
{
	lunghezza = 0;
	dimensione = dim;
	v = new T [dimensione];
}

template<class T>
listaVect<T>::~listaVect()
{
	delete[] v;
}

template<class T>
listaVect<T>::listaVect(const listaVect<T>& l)
{
	dimensione = l.dimensione;
	lunghezza = l.lunghezza;
	v = new T[dimensione];
	for(int i = 0; i < lunghezza; i++)
	{
		v[i] = l.v[i];
	}
}

template<class T>
void listaVect<T>::create()
{
	dimensione = 10;
	lunghezza = 0;
	v = new T [dimensione];
}

template<class T>
bool listaVect<T>::empty()
{
	if(lunghezza == 0)
		return true;
	else
		return false;
}

template<class T>
typename listaVect<T>::tipoelem listaVect<T>:: read(posizione p)
{
	if(p > 0 && p <= lunghezza+1)		//chiedi al prof
		return v[p-1];
	else
		return v[p];
}

template<class T>
void listaVect<T>::write(tipoelem x, posizione p)
{
	if(p > 0 && p <= lunghezza+1)
		v[p-1] = x;
}

template<class T>
typename listaVect<T>::posizione listaVect<T>:: begin()
{
	return 1;
}

template<class T>
bool listaVect<T>::end(posizione p)
{
	if(p > 0 && p <= lunghezza+1)
	{
		if(p == lunghezza+1)
			return true;
		else
			return false;
	}
	else
		return false;
}

template<class T>
typename listaVect<T>::posizione listaVect<T>:: next(posizione p)
{
	if(p > 0 && p <= lunghezza+1)
		return p+1;
	else
		return p;
}

template<class T>
typename listaVect<T>::posizione listaVect<T>:: pred(posizione p)
{
	if(p > 1 && p <= lunghezza+1)
		return p-1;
	else
		return p;
}

template<class T>
void listaVect<T>::insert(tipoelem x, posizione& p)
{
	if(lunghezza == dimensione)
	{
		change_dimension(v, dimensione, dimensione*2);
		dimensione = dimensione*2;
	}
	if(p > 0 && p <= lunghezza+1)
	{
		for(int i = lunghezza; i >= p; i--)
		{
			v[i] = v[i-1];
		}
		v[p-1] = x;
		lunghezza++;
	}
}

template<class T>
void listaVect<T>::erase(posizione& p)
{
	if(empty() == false)
	{
		for(int i = p-1; i < lunghezza-1; i++)
		{
			v[i] = v[i+1];
		}
	}
	lunghezza--;
}

template<class T>
bool listaVect<T>::operator==(const listaVect<T> & vet)
{
	if(vet.lunghezza != this->lunghezza)
		return false;
	else
	{
		for(int i = 0; i < vet.lunghezza; i++)
		{
			if(vet.v[i] != this->v[i])
				return false;
		}
	}
	return true;
}

template<class T>
listaVect<T>& listaVect<T>::operator=(const listaVect<T>& vet)
{
	//controllo per evitare gli autoassegnamenti
	if(this != &vet)
	{
		this->dimensione = vet.dimensione;
		this->lunghezza = vet.lunghezza;
		delete this->v;
		this->v = new T[dimensione];
		for(int i = 0; i < lunghezza; i++)
		{
			this->v[i] = vet.v[i];
		}
	}
	return *this;
}

template<class T>
void listaVect<T>::change_dimension(T*& vet, int dim , int dim2)
{
	T* temp = new T[dim2];
	int number;
	if(dim < dim2)
		number = dim;
	else
		number = dim2;
	for(int i = 0; i < number; i++)
	{
		temp[i] = v[i];
	}
	delete v;
	v = temp;

}




#endif /* LISTAVECT_H_ */
