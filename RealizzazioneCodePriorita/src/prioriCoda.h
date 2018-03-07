/*
 * prioriCoda.h
 *
 *  Created on: 17 dic 2016
 *      Author: Paolo
 */

#ifndef PRIORICODA_H_
#define PRIORICODA_H_

#include<iostream>
using namespace std;

template <class T>
class prioriCoda {
public:
	typedef T tipoelem;

	void creaPrioriCoda();
	void inserisci (tipoelem);
	tipoelem min ();
	void cancellaMin ();
};
#endif /* PRIORICODA_H_ */
