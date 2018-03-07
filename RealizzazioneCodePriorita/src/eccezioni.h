/*
 * eccezioni.h
 *
 *  Created on: 02 nov 2016
 *      Author: Paolo
 */

#ifndef ECCEZIONI_H_
#define ECCEZIONI_H_

#include <stdexcept>
using namespace std;

struct nullNode : invalid_argument
{
	nullNode():invalid_argument("Parametro nodo nullo"){};
};

struct fullSize : invalid_argument
{
	fullSize():invalid_argument("Dimensione massima raggiunta"){}
};

struct rootExists : domain_error
{
	rootExists():domain_error("Radice gia' presente"){};
};

struct nodeExists:domain_error
{
	nodeExists():domain_error("Nodo gia' presente"){};
};

struct emptyTree:domain_error
{
	emptyTree():domain_error("L'albero e' vuoto"){};
};

#endif /* ECCEZIONI_H_ */
