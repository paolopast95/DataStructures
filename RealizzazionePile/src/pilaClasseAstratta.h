/*
 * pilaClasseAstratta.h
 *
 *  Created on: 26 ott 2016
 *      Author: Paolo
 */

#ifndef PILACLASSEASTRATTA_H_
#define PILACLASSEASTRATTA_H_


//creazione della classe astratta pila
template<class T, class P>
class pila{
public:
	//creazione alias
	typedef T tipoelem;
	typedef P posizione;

	//metodi
	virtual void createStack() = 0;
	virtual bool emptyStack() = 0;
	virtual tipoelem readStack() = 0;
	virtual void push(tipoelem) = 0;
	virtual void pop() = 0;
};


#endif /* PILACLASSEASTRATTA_H_ */
