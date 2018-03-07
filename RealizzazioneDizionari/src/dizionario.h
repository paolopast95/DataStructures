/*
 * dizionario.h
 *
 *  Created on: 23 nov 2016
 *      Author: Paolo
 */

#ifndef DIZIONARIO_H_
#define DIZIONARIO_H_

template<class K, class E>
struct coppia
{
	K chiave;
	E valore;

	//metodi
	coppia(){};	//costruttore
	coppia(coppia<K,E>& CP)	//costruttore di copia
	{
		chiave = CP.chiave;
		valore = CP.valore;
	}
};


template<class K, class E>
class dizionario
{
	virtual void create() = 0;
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual coppia<K, E>* find(K&) = 0;
	virtual void insert(coppia<K, E>&) = 0;
	virtual void erase(K&) = 0;
	virtual void modify(K&, E&) = 0;
};


#endif /* DIZIONARIO_H_ */
