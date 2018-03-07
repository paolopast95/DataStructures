/*
 * tavolaHash.h
 *
 *  Created on: 23 nov 2016
 *      Author: Paolo
 */

#ifndef TAVOLAHASH_H_
#define TAVOLAHASH_H_

#include<iostream>
#include<string>
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
struct mypair;

template<class K, class E>
class tavolaHash :public dizionario< K, E >
{
public:
	tavolaHash();
	tavolaHash(int);
	~tavolaHash();
	void create();
	bool empty();
	int size();
	int search(K& );
	coppia<K, E>* find(K&);
	void insert(coppia<K, E>&);
	void erase(K&);
	void modify(K&, E&);

private:
	coppia<K, E>** table;		//tavola
	hash<K> hashm;				//converte una chiave in un intero non negativo
	int lunghezza;				//numero elementi inseriti nella tabella
	int divisore;				//dimensione massima della tabella
};


template<class K, class E>
tavolaHash<K, E>::tavolaHash()
{
	divisore = 20;
	lunghezza = 0;
	table = new coppia<K, E>* [divisore];
	for(int i = 0; i < divisore; i++)
	{
		table[i] = NULL;
	}
}

template<class K, class E>
tavolaHash<K, E>::tavolaHash(int d)
{
	divisore = d;
	lunghezza = 0;
	table = new coppia<K, E>* [divisore];
	for(int i = 0; i < divisore; i++)
	{
		table[i] = NULL;
	}
}

template<class K, class E>
tavolaHash<K, E>::~tavolaHash()
{
	delete[] table;
}

template<class K, class E>
void tavolaHash<K, E>::create()
{
	divisore = 20;
	lunghezza = 0;
	table = new coppia<K, E>* [divisore];
	for(int i = 0; i < divisore; i++)
	{
		table[i] = NULL;
	}
}

template<class K, class E>
bool tavolaHash<K,E>::empty()
{
	return (lunghezza == 0);
}

template<class K, class E>
int tavolaHash<K,E>::size()
{
	return lunghezza;
}

template<class K, class E>
int tavolaHash<K,E>::search(K& k)
{
	int i = (int) hashm(k) % divisore;
	int j = i;
	do{
		if(table[j]==NULL || table[j]->chiave == k)
			return j;
		j = (j+1)%divisore;
	}while(i != j);
	return j;
}


template<class K, class E>
coppia<K, E>* tavolaHash<K,E>::find(K& k)
{
	int i = search(k);
	if(table[i] == NULL || table[i]->chiave != k)
		return NULL;
	else
		return table[i];
}

template<class K, class E>
void tavolaHash<K,E>::insert(coppia<K, E>& P)
{
	int i = search(P.chiave);
	if(table[i] == NULL)
	{
		table[i] = new coppia<K,E>(P);
		lunghezza++;
	}
	else
	{
		if(table[i]->chiave == P.chiave)
		{
			table[i]->valore = P.valore;
		}
		else
			cout << "tabella hash piena\n";
	}
}

template<class K, class E>
void tavolaHash<K,E>::erase(K& k)
{
	int i = search(k);
	if(table[i] != NULL && table[i]->chiave == k)
	{
		table[i] = NULL;
		i++;
		while(table[i] != NULL && search(table[i]->chiave) != i)
		{
			table[(i-1)%divisore] = table[i%divisore];
		}
	}
}

template <class K, class E>
void tavolaHash<K,E>::modify(K& k, E& e)
{
	int i = search(k);
	if(table[i] != NULL && table[i]->chiave == k)
	{
		table[i]->valore = e;
	}
	else
		cout <<"chiave non presente! Impossibile aggiornare\n";
}

#endif /* TAVOLAHASH_H_ */
