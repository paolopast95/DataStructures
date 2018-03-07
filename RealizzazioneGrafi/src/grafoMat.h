/*
 * grafoMat.h
 *
 *  Created on: 14 dic 2016
 *      Author: Paolo
 */

#ifndef GRAFOMAT_H_
#define GRAFOMAT_H_

#include "grafo.h"

template<class P>
class infoArco{
public:
	P peso;
	bool vuoto;

	infoArco(){vuoto = true;}
};

template<class E, class P>
class infoNodo{
public:
	E   etichetta;
	bool vuoto;
	infoArco<P>* archi;

	infoNodo(){
		vuoto = true;
	}

	~infoNodo(){
		if (!vuoto)
			delete [] archi;
	}
};


class nodoG{
 public:
	nodoG(int i){
		nodoId = i;
	}

	nodoG(){}

	int getId(){ return nodoId; }
	void setId(int id) {nodoId = id;}
 private:
	int nodoId;
};


template<class E, class P>
class grafoMat : public grafo<E, P, nodoG>{

public:
    typedef E etichetta;
    typedef P peso;
    typedef nodoG nodo;
    typedef arco<peso, nodo> arco;
    typedef grafo<etichetta, peso, nodo> grafo;
    typedef typename grafo::listaNodi listaNodi;
	typedef typename grafo::listaNodiPos listaNodiPos;

    grafoMat(int);
    ~grafoMat();

    bool vuoto() const;
    void insNodo(nodoG&);
    void insArco(nodo, nodo, peso);
    void cancNodo(nodo);
    void cancArco(nodo, nodo);
	//bool esisteNodo(nodo);
	//bool esisteArco(arco);
    listaNodi adiacenti(nodo) const ;
    listaNodi listNodi() const ;
    etichetta leggiEtichetta(nodo) const ;
    void scriviEtichetta(nodo,etichetta) ;
    peso leggiPeso(nodo, nodo) const ;
    void scriviPeso(nodo, nodo, peso) ;
    int numNodi();
    int numArchi();


 private:
    infoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
	int archi;
};

template<class E, class P>
grafoMat<E,P>::grafoMat(int x)
{
	dimensione = x;
	nodi = 0;
	archi = 0;
	matrice = new infoNodo<E, P>[dimensione];
	for(int i = 0; i < dimensione; i++)
	{
		matrice[i].vuoto = true;
		matrice[i].archi = new infoArco<peso>[dimensione];
	}
}

template<class E, class P>
grafoMat<E,P>::~grafoMat()
{
	delete[] matrice;
}

template<class E, class P>
bool grafoMat<E,P>::vuoto() const
{
	return(nodi == 0);
}


template<class E, class P>
void grafoMat<E, P>::insNodo(nodo& n)
{
	int pos = 0;
	if(nodi < dimensione)
	{
		while(matrice[pos].vuoto == false)
			pos++;
		n.setId(pos);
		matrice[pos].vuoto = false;
		nodi++;
	}
}

template<class E, class P>
void grafoMat<E,P>::insArco(nodo n1, nodo n2, peso p)
{
	matrice[n1.getId()].archi[n2.getId()].peso = p;
	matrice[n1.getId()].archi[n2.getId()].vuoto = false;
	archi++;
}

template<class E, class P>
void grafoMat<E,P>::cancNodo(nodo n1)
{
	bool canc = true;
	//controllo che non ci siano archi uscenti
	for(int i = 0; i < dimensione && canc; i++)
	{
		if(matrice[n1.getId()].archi[i].vuoto == false)
			canc = false;
	}
	for(int i = 0; i < dimensione && canc; i++)
	{
		if(matrice[i].archi[n1.getId()].vuoto == false)
			canc = false;
	}

	//cancellazione
	if(canc == true)
	{
		matrice[n1.getId()].vuoto = true;
		nodi--;
	}
}


template<class E, class P>
void grafoMat<E,P>::cancArco(nodo n1, nodo n2)
{
	matrice[n2.getId()].archi[n2.getId()].vuoto = true;
	archi--;
}

template<class E, class P>
typename grafoMat<E,P>::listaNodi grafoMat<E,P>::listNodi() const
{
	listaNodi list;
	for(int i = 0; i < dimensione; i++)
	{
		if(matrice[i].vuoto == false)
		{
			listaNodiPos p;
			p = list.begin();
			list.insert(new nodoG(i), p);
		}
	}
	return list;
}

template<class E, class P>
typename grafoMat<E,P>::listaNodi grafoMat<E,P>::adiacenti(nodo n1) const
{
	listaNodi list;
	for(int i = 0; i < dimensione; i++)
	{
		if(matrice[n1.getId()].archi[i].vuoto == false)
		{
			listaNodiPos p;
			p = list.begin();
			list.insert(new nodoG(i), p);
		}
	}
	return list;
}


template<class E, class P>
typename grafoMat<E,P>::etichetta grafoMat<E,P>::leggiEtichetta(nodo n1) const
{
	return matrice[n1.getId()].etichetta;
}

template<class E, class P>
void grafoMat<E,P>::scriviEtichetta(nodo n1, etichetta l)
{
	matrice[n1.getId()].etichetta = l;
}


template<class E, class P>
typename grafoMat<E,P>::peso grafoMat<E,P>::leggiPeso(nodo n1, nodo n2) const
{
	return matrice[n1.getId()].archi[n2.getId()].peso;
}

template<class E, class P>
void grafoMat<E,P>::scriviPeso(nodo n1, nodo n2, peso p)
{
	matrice[n1.getId()].archi[n2.getId()].peso = p;
}


template<class E, class P>
int grafoMat<E,P>::numNodi()
{
	return nodi;
}

template<class E, class P>
int grafoMat<E,P>::numArchi()
{
	return archi;
}

#endif /* GRAFOMAT_H_ */
