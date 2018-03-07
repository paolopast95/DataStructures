/*
 * tavolaHashTrabocco.h
 *
 *  Created on: 23 nov 2016
 *      Author: Paolo
 */

#ifndef TAVOLAHASHTRABOCCO_H_
#define TAVOLAHASHTRABOCCO_H_


#include<string>
#include"listaVect.h"
#include"dizionario.h"
using namespace std;

//definizione della funzione hash
template<class T>
class hash
{
public:
	size_t operator()(const T chiave) const;
};

//implementazione del metodo per le stringhe
template<>
class hash<string>
{
public:
	size_t operator()(const string chiave) const
	{
		long hashV = 0;
		int lunghezza = (int) chiave.length();
		for(int i = 0; i < lunghezza; i++)
		{
			hashV = 5*hashV + chiave.at(i);
		}
		return size_t(hashV);
	}
};

//implementazione per gli interi
template<>
class hash<int>
{
public:
	size_t operator()(const int chiave) const
	{
		return size_t(chiave);
	}
};

//implementazione per i caratteri
template<>
class hash<char>
{
public:
	size_t operator()(const char chiave) const
	{
		int hashV;
		hashV = (int)chiave;
		return size_t(hashV);
	}
};


//definizione della classe tavolaHash

template<class K, class E>
class tavolaHashTrabocco :public dizionario< K, E >
{
public:
	tavolaHashTrabocco();
	tavolaHashTrabocco(int);
	~tavolaHashTrabocco();
	void create();
	bool empty();
	int size();
	int search(K& );
	coppia<K, E>* find(K&);
	void insert(coppia<K, E>&);
	void erase(K&);
	void modify(K&, E&);

private:
	listaVect<coppia<K, E> > *table;		//tavola
	hash<K> hashm;					//converte una chiave in un intero non negativo
	int lunghezza;				//numero elementi inseriti nella tabella
	int divisore;				//dimensione massima della tabella
};


template<class K, class E>
tavolaHashTrabocco<K, E>::tavolaHashTrabocco()
{
	divisore = 20;
	lunghezza = 0;
	table = new listaVect<coppia<K, E> >[divisore];
}

template<class K, class E>
tavolaHashTrabocco<K, E>::tavolaHashTrabocco(int d)
{
	divisore = d;
	lunghezza = 0;
	table = new listaVect<coppia<K, E> >[divisore];
}

template<class K, class E>
tavolaHashTrabocco<K, E>::~tavolaHashTrabocco()
{
	delete[] table;
}

template<class K, class E>
void tavolaHashTrabocco<K, E>::create()
{
	divisore = 20;
	lunghezza = 0;
	table = new listaVect<coppia<K,E> >[divisore];
}

template<class K, class E>
bool tavolaHashTrabocco<K,E>::empty()
{
	return (lunghezza == 0);
}

template<class K, class E>
int tavolaHashTrabocco<K,E>::size()
{
	return lunghezza;
}

//search restituisce la posizione nella tabella dove è possibile trovare l'elemento di chiave k(non è detto che sia presente)
template<class K, class E>
int tavolaHashTrabocco<K,E>::search(K& k)
{
	int i = (int) hashm(k) % divisore;
	return i;
}


template<class K, class E>
coppia<K, E>* tavolaHashTrabocco<K,E>::find(K& k)
{
	coppia<K,E>* ris = new coppia<K,E>;
	int i = search(k);
	typename listaVect<coppia<K, E> >::posizione pos;
	pos = table[i].begin();
	while(table[i].end(pos) == false && table[i].read(pos).chiave != k)
	{
		pos = table[i].next(pos);
	}
	if(table[i].end(pos) == true)
		return NULL;
	else
	{
		ris->chiave = table[i].read(pos).chiave;
		ris->valore = table[i].read(pos).valore;
		return ris;
	}
}

template<class K, class E>
void tavolaHashTrabocco<K,E>::insert(coppia<K, E>& P)
{
	int i = search(P.chiave);
	coppia<K, E> temp;
	typename listaVect< coppia< K, E > >::posizione pos;
	pos = table[i].begin();
	while(table[i].end(pos) == false && table[i].read(pos).chiave != P.chiave)
	{
		pos = table[i].next(pos);
	}
	if(table[i].end(pos) == true)
	{
		table[i].insert(P, pos);
	}
	else
	{
		table[i].erase(pos);
		table[i].insert(P, pos);
	}
}

template<class K, class E>
void tavolaHashTrabocco<K,E>::erase(K& k)
{
	int i = search(k);
	typename listaVect<coppia<K, E> >::posizione pos;
	pos = table[i].begin();
	while(table[i].end(pos) == false && table[i].read(pos).chiave != k)
	{
		pos = table[i].next(pos);
	}
	if(table[i].end(pos) == false)
	{
		table[i].erase(pos);
	}
}

template<class K, class E>
void tavolaHashTrabocco<K,E>::modify(K& k, E& e)
{
	int i = search(k);
	typename listaVect<coppia<K, E> >::posizione pos;
	pos = table[i].begin();
	while(table[i].end(pos) == false && table[i].read(pos).chiave != k)
	{
		pos = table[i].next(pos);
	}
	if(table[i].end(pos) == false)
	{
		coppia<K,E> temp;
		temp.chiave = k;
		temp.valore = e;
		table[i].write(temp, pos);
	}
	else
	{
		cout << "Impossibile aggiornare! Chiave non presente\n\n";
	}
}
#endif /* TAVOLAHASHTRABOCCO_H_ */
