/*
 * prioriCodaPunt.h
 *
 *  Created on: 17 dic 2016
 *      Author: Paolo
 */

#ifndef PRIORICODATREE_H_
#define PRIORICODATREE_H_

#include"BinTreeP.h"
#include"prioriCoda.h"

template<class T>
class prioriCodaTree : public prioriCoda<T>{
public:
	typedef typename prioriCoda<T>::tipoelem tipoelem;

	prioriCodaTree();
	~prioriCodaTree();
	void creaPrioriCoda();
	void inserisci(tipoelem);
	tipoelem min();
	void cancellaMin();

private:
	binTreeP<tipoelem> tree;
	typename binTreeP<tipoelem>::nodo ultimo;
};

template<class T>
prioriCodaTree<T>::prioriCodaTree()
{
	creaPrioriCoda();
}

template<class T>
prioriCodaTree<T>::~prioriCodaTree()
{
	ultimo = NULL;
	tree.erase(tree.root());
}

template<class T>
void prioriCodaTree<T>::creaPrioriCoda()
{
	tree.create();
	ultimo = NULL;
}

template<class T>
typename prioriCodaTree<T>::tipoelem prioriCodaTree<T>::min()
{
	return tree.read(tree.root());
}

template<class T>
void prioriCodaTree<T>::inserisci(tipoelem x)
{
	//se la coda è vuota
	if(tree.isEmpty())
	{
		tree.insRoot();
		tree.write(tree.root(), x);
		ultimo = tree.root();
	}

	else
	{
		typename binTreeP<tipoelem>::nodo scorri = ultimo;
		//se la coda ha solo la radice
		if(ultimo == tree.root())
		{
			tree.insSx(tree.root());
			tree.write(tree.sx(tree.root()), x);
			ultimo = tree.sx(tree.root());
		}
		else
		{

			//se ultimo è un figlio sinistro si inserisci come fratello destro
			if(tree.sx(tree.parent(scorri)) == ultimo)
			{
				tree.insDx(tree.parent(scorri));
				tree.write(tree.dx(tree.parent(scorri)), x);
				ultimo = tree.dx(tree.parent(scorri));
			}
			else
			{
				//se ultimo è figlio destro si risale fino a che non si raggiunge la radice o si raggiunge un figlio sinistro
				while(scorri != tree.root() && tree.dx(tree.parent(scorri)) == scorri)
				{
					scorri = tree.parent(scorri);
				}
				if(scorri != tree.root())
				{
					scorri = tree.dx(tree.parent(scorri));
				}
				while(!(tree.sxEmpty(scorri) && tree.dxEmpty(scorri)))
					scorri = tree.sx(scorri);
				tree.insSx(scorri);
				tree.write(tree.sx(scorri), x);
				ultimo = tree.sx(scorri);
			}
		}
		scorri = ultimo;
		while(scorri != tree.root() && tree.read(scorri) < tree.read(tree.parent(scorri)))
		{
			tipoelem temp;
			temp = tree.read(scorri);
			tree.write(scorri, tree.read(tree.parent(scorri)));
			tree.write(tree.parent(scorri), temp);
			scorri = tree.parent(scorri);
		}
	}
}

template<class T>
void prioriCodaTree<T>::cancellaMin()
{
	if(!tree.isEmpty())
	{
		if(ultimo == tree.root())
		{
			tree.erase(ultimo);
			ultimo = NULL;
		}
		else
		{
			typename binTreeP<tipoelem>::nodo scorri = ultimo;
			tree.write(tree.root(),tree.read(ultimo));

			//fase di modifica della struttura e aggiornamento dell'ultimo
			if(tree.dx(tree.parent(ultimo)) == ultimo)
				ultimo = tree.sx(tree.parent(ultimo));
			else
			{

				while(scorri != tree.root() && tree.sx(tree.parent(scorri)) == scorri)
				{
					scorri = tree.parent(scorri);
				}
				if(scorri != tree.root())
				{
					scorri = tree.dx(tree.parent(scorri));
				}
				while(!(tree.sxEmpty(scorri) && tree.dxEmpty(scorri)))
				{
					scorri = tree.dx(scorri);
				}
				tree.erase(ultimo);
				ultimo = scorri;
			}

			//fase di aggiornamento delle priorità
			scorri = tree.root();
			while(!(tree.sxEmpty(scorri) && tree.dxEmpty(scorri)) && (tree.read(scorri) > tree.read(tree.sx(scorri)) || tree.read(scorri) > tree.read(tree.dx(scorri))))
			{
				if(!tree.sxEmpty(scorri) && !tree.dxEmpty(scorri))
				{
					if(tree.read(tree.sx(scorri)) > tree.read(tree.dx(scorri)))
					{
						tipoelem temp;
						temp = tree.read(scorri);
						tree.write(scorri, tree.read(tree.dx(scorri)));
						tree.write(tree.dx(scorri),temp);
						scorri = tree.dx(scorri);
					}
					else
					{
						tipoelem temp;
						temp = tree.read(scorri);
						tree.write(scorri, tree.read(tree.sx(scorri)));
						tree.write(tree.sx(scorri),temp);
					}
				}
				else
				{
					tipoelem temp;
					temp = tree.read(scorri);
					tree.write(scorri, tree.read(tree.sx(scorri)));
					tree.write(tree.sx(scorri),temp);
					tree.sx(scorri);
				}
			}
		}
	}
}
#endif /* PRIORICODATREE_H_ */
