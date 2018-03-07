/*
 * set.h
 *
 *  Created on: 26 dic 2016
 *      Author: Paolo
 */

#ifndef SET_H_
#define SET_H_

template<class T>
class set
{
public:
	typedef T tipoelem;

	//crea un insieme vuoto
	virtual void create() = 0;
	//controlla che l'insieme sia vuoto
	virtual bool emptySet() = 0;
	//controlla che un elemento sia nell'insieme
	virtual bool isIn(tipoelem) = 0;
	//inserisce un elemento nell'insieme
	virtual void insert(tipoelem) = 0;
	//cancella un elemento dall'insieme
	virtual void erase(tipoelem) = 0;
	//stampa l'insieme
	virtual void printSet() = 0;
};



#endif /* SET_H_ */
