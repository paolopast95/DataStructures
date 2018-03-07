/*
 * grafoList.h
 *
 *  Created on: 14 dic 2016
 *      Author: Paolo
 */

#ifndef GRAFOLIST_H_
#define GRAFOLIST_H_

#include"listaMono.h"
#include"grafo.h"

class nodoG{
 public:
  nodoG(int i){
    nodoId = i;
  }
  nodoG(){
  }
  int getId(){ return nodoId; }
  void setId(int id) {nodoId = id;}
  bool operator==(const nodoG n) {return nodoId == n.nodoId;}
 private:
  int nodoId;
};



template<class P>
class infoArco {
 public:
  P peso;
  nodoG _to;
};



template<class E, class P>
class infoNodo{
public:
	E etichetta;
	bool vuoto;
	listaMono<infoArco<P> > archi;

	infoNodo(){
		vuoto = true;
	}
};


template<class E, class P>
class grafoList : public grafo<E, P, nodoG> {
public:
    typedef E etichetta;
    typedef P peso;
    typedef nodoG nodo;
    typedef arco<peso, nodo> arco;
    typedef grafo<etichetta, peso, nodo> grafo;
    typedef typename grafo::listaNodi listaNodi;
    typedef typename grafo::listaNodiPos listaNodiPos;

    grafoList(int);
    ~grafoList();

    bool vuoto() const;
    void insNodo(nodoG&);
    void insArco(nodo, nodo, peso);
    void cancNodo(nodo);
    void cancArco(nodo, nodo);
    //    bool esisteNodo(Nodo);
    //    bool esisteArco(Arco);
    listaNodi adiacenti(nodo) const ;
    listaNodi listNodi() const ;
    etichetta leggiEtichetta(nodo) const ;
    void scriviEtichetta(nodo, etichetta) ;
    peso leggiPeso(nodo, nodo) const ;
    void scriviPeso(nodo, nodo, peso) ;

    int numNodi(){
      return nodi;
    };
    int numArchi(){
      return archi;
    };


 private:
    infoNodo<E,P>* matrice;
    int dimensione;
    int nodi;
    int archi;
};

template<class E, class P>
grafoList<E,P>::grafoList(int x)
{
	dimensione = x;
	nodi = 0;
	archi = 0;
	matrice = new infoNodo<E, P>[dimensione];
	for(int i = 0; i < dimensione; i++)
	{
		matrice[i].vuoto = true;
		matrice[i].archi.create();
	}
}


template<class E, class P>
grafoList<E,P>::~grafoList()
{
	delete[] matrice;
}

template<class E, class P>
bool grafoList<E,P>::vuoto() const
{
	return(nodi == 0);
}

template<class E, class P>
void grafoList<E,P>::insNodo(nodoG& n)
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
void grafoList<E,P>::insArco(nodo n1, nodo n2, peso p)
{
	infoArco<peso> I;
	I._to = n2;
	I.peso = p;
	typename listaMono<infoArco<P> >::posizione pos = matrice[n1.getId()].archi.begin();
	matrice[n1.getId()].archi.insert(I,pos);
	archi++;
}

template<class E, class P>
void grafoList<E,P>::cancNodo(nodo n)
{
	bool canc = true;
	//controllo archi uscenti da n
	if(matrice[n.getId()].archi.empty() == true)
		canc = false;

	//controllo archi entranti
	for(int i = 0; i < dimensione && canc == true; i++)
	{
		if(matrice[i].vuoto == false)
		{
			typename listaMono<infoArco<P> >::posizione pos = matrice[i].archi.begin();
			while(matrice[i].archi.end(pos) == false && canc == true)
			{
				if(matrice[i].archi.read(pos)._to.getId() == n.getId())
					canc = false;
				else
					pos = matrice[i].archi.next(pos);
			}
		}
	}
	if(canc)
	{
		matrice[n.getId()].vuoto = true;
		nodi--;
	}
}

template<class E, class P>
void grafoList<E,P>::cancArco(nodo n1, nodo n2)
{
	bool trovato = false;
	typename listaMono<infoArco<P> >::posizione pos;
	pos = matrice[n1.getId()].archi.begin();
	while(matrice[n1.getId()].archi.end(pos) == false && trovato == false)
	{
		if(matrice[n1.getId()].archi.read(pos)._to.getId() == n2.getId())
			trovato = true;
		else
			pos = matrice[n1.getId()].archi.next(pos);
	}
	if(trovato == true)
	{
		matrice[n1.getId()].archi.erase(pos);
		archi--;
	}
}
template<class E, class P>
typename grafoList<E,P>::listaNodi grafoList<E,P>::adiacenti(nodo n) const
{
	listaNodi list;
	listaNodiPos pos = list.begin();
	typename listaMono<infoArco<P> >::posizione posArco = matrice[n.getId()].archi.begin();
	while(matrice[n.getId()].archi.end(posArco) == false)
	{
		list.insert(new nodoG(matrice[n.getId()].archi.read(posArco)._to.getId()), pos);
		posArco = matrice[n.getId()].archi.next(posArco);
	}
	return list;
}

template<class E, class P>
typename grafoList<E,P>::listaNodi grafoList<E,P>::listNodi() const
{
	listaNodi list;
	listaNodiPos pos = list.begin();
	for(int i = 0; i < dimensione; i++)
	{
		if(matrice[i].vuoto == false)
		{
			list.insert(new nodoG(i), pos);
		}
	}
	return list;
}

template<class E, class P>
typename grafoList<E,P>::etichetta grafoList<E,P>::leggiEtichetta(nodo n) const
{
	return matrice[n.getId()].etichetta;
}

template<class E, class P>
void grafoList<E,P>::scriviEtichetta(nodo n, etichetta e)
{
	matrice[n.getId()].etichetta = e;
}

template<class E, class P>
typename grafoList<E,P>::peso grafoList<E,P>::leggiPeso(nodo n1, nodo n2) const
{
	typename listaMono<infoArco<P> >::posizione pos;
	bool trovato = false;
	pos = matrice[n1.getId()].archi.begin();
	while(matrice[n1.getId()].archi.end(pos) == false && trovato == false)
	{
		if(matrice[n1.getId()].archi.read(pos)._to.getId() == n2.getId())
			trovato = true;
		else
			pos = matrice[n1.getId()].archi.next(pos);
	}
	if(trovato == true)
		return matrice[n1.getId()].archi.read(pos).peso;
}

template<class E, class P>
void grafoList<E, P>::scriviPeso(nodo n1, nodo n2, peso p)
{
	bool trovato = false;
	typename listaMono<infoArco<P> >::posizione pos;
	pos = matrice[n1.getId()].archi.begin();
	while(matrice[n1.getId()].archi.end(pos) == false && trovato == false)
	{
		if(matrice[n1.getId()].archi.read(pos)._to.getId() == n2.getId())
			trovato = false;
		else
			pos = matrice[n1.getId()].archi.next(pos);
	}
	if(trovato == true)
	{
		infoArco<P> I;
		I._to = n2;
		I.peso = p;
		matrice[n1.getId()].archi.write(I,pos);
	}
}
#endif /* GRAFOLIST_H_ */
