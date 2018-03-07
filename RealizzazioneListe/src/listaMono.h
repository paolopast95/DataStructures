#include <iostream>
#include "listaLineare.h"
#include "cellaMono.h"
using namespace std;


//creazione della classe listaMono
//listaMono è l'insieme delle liste monodirezionali
template<class T>
class listaMono : public listaLineare<T, cellaMono<T>*>
{
public:
	//creazione degli alias per tipoelem e cellaMono<T>*
	typedef typename listaLineare<T, cellaMono<T>*>::posizione posizione;
	typedef typename listaLineare<T, cellaMono<T>*>::tipoelem tipoelem;

	//costruttori, distruttore e costruttore di copia
	listaMono();
	~listaMono();
	listaMono(listaMono<T>&);

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
	listaMono<T>& operator=(listaMono<T>&);
	bool operator==(listaMono<T>&);

private:
	posizione lista;
};

template<class T>
listaMono<T>::listaMono()
{
	lista = NULL;
}

template<class T>
listaMono<T>::~listaMono()
{
	posizione temp;
	while(lista != NULL)
	{
		erase(lista);
	}
	delete(lista);
}

template<class T>
listaMono<T>::listaMono(listaMono<T>& l)
{
	posizione scorri, corr;
	scorri = l.begin();
	this->create();
	corr = this->begin();
	while(l.end(scorri) == false)
	{
		this->insert(l.read(scorri), corr);
		scorri = l.next(scorri);
		corr = this->next(corr);
	}

}

template<class T>
void listaMono<T>::create()
{
	lista = NULL;
}

template<class T>
bool listaMono<T>::empty()
{
	if(lista == NULL)
		return true;
	else
		return false;
}

template<class T>
typename listaMono<T>::tipoelem listaMono<T>::read(posizione p)
{
	return p->getElemento();
}

template<class T>
void listaMono<T>::write(tipoelem x, posizione p)
{
	p->setElemento(x );
}

template<class T>
typename listaMono<T>::posizione listaMono<T>::begin()
{
	return lista;
}

template<class T>
bool listaMono<T>::end(posizione p)
{
	if(p == NULL)
		return true;
	else
		return false;
}

template<class T>
typename listaMono<T>::posizione listaMono<T>::next(posizione p)
{
	return p->getSucc();
}

template<class T>
typename listaMono<T>:: posizione listaMono<T>::pred(posizione p)
{
	posizione ris;
	ris = begin();
	if(ris != p)
	{
		while(ris->getSucc() != p)
		{
			ris = next(ris);
		}
	}
	return ris;
}

template<class T>
void listaMono<T>::insert(tipoelem x, posizione& p)
{
	posizione temp;
	posizione previous;
	temp = (cellaMono<tipoelem>*)malloc(sizeof(cella<tipoelem>));
	temp->setElemento(x);
	previous = pred(p);
	if(lista == NULL)
	{
		temp->setSucc(NULL);
		lista = temp;
		p = lista;
	}
	else if(p == lista)
	{
		temp->setSucc(lista);
		lista = temp;
		p = lista;
	}
	else
	{
		temp->setSucc(p);
		previous->setSucc(temp);
		p = temp;
	}
}

template<class T>
void listaMono<T>::erase(posizione& p)
{
	posizione previous;
	posizione temp;
	previous = pred(p);
	if(previous == p)
	{
		temp = p;
		lista = p->getSucc();
		delete temp;
		p = lista;
	}
	else
	{
		temp = p;
		previous->setSucc(p->getSucc());
		p = p->getSucc();
		delete temp;

	}
}

template<class T>
listaMono<T>& listaMono<T>::operator=(listaMono<T>& l)
{
	posizione scorri, corr;
	//per evitare gli autoassegnamenti del tipo l = l;
	if(*this == l)
		return *this;
	else
	{
		this->~listaMono();
		this->create();
		scorri = l.begin();
		corr = this->begin();
		while(l.end(scorri) == false)
		{
			this->insert(l.read(scorri), corr);
			corr = this->next(corr);
			scorri = l.next(scorri);
		}
		return *this;
	}
}

template<class T>
bool listaMono<T>::operator==(listaMono<T>& l)
{
	posizione scorri1, scorri2;
	scorri1 = l.begin();
	scorri2 = this->begin();
	while(l.end(scorri1) == false && this->end(scorri2) == false)
	{
		if(l.read(scorri1) != this->read(scorri2))
			return false;
		scorri1 = l.next(scorri1);
		scorri2 = this->next(scorri2);
	}
	if(l.end(scorri1) == true && this->end(scorri2) == false)
		return false;
	else if(l.end(scorri1) == false && this->end(scorri2) == true)
		return false;
	else
		return true;
}
