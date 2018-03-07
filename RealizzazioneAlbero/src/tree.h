/*
 * tree.h
 *
 *  Created on: 30 nov 2016
 *      Author: Paolo
 */

#ifndef TREE_H_
#define TREE_H_


template<class T, class N>
class tree{
public:
	typedef T tipoelem;
	typedef N node;

	virtual void create () = 0;
	virtual bool empty () = 0;
	virtual void insRoot () = 0;
	virtual node root () = 0;
	virtual node parent (node) = 0;
	virtual bool leaf (node) = 0;
	virtual node firstChild (node) = 0;
	virtual bool lastSibling (node) = 0;
	virtual node nextSibling (node) = 0;
	virtual void writeNode (node, tipoelem) = 0;
	virtual tipoelem readNode (node) = 0;
	//virtual void insFirstSubTree(node, tree<T,N>&);
	//virtual void insSubTree(node, tree<T, N>&);
	//implementazione funzioni profondità e larghezza
	int profondita(node);
	int larghezza(node);

private:
	void copiaSottoAlbero(node, tree<T, N>&, node);
};


template<class T, class N>
int tree<T,N>::profondita(node R)
{
	node scorriFigli;
	int max = 0;
	int corr;
	if(leaf(R) == true)
	{
		return max;
	}
	else
	{
		scorriFigli = firstChild(R);
		max = profondita(scorriFigli);
		while(!lastSibling(scorriFigli))
		{
			scorriFigli = nextSibling(scorriFigli);
			corr = profondita(scorriFigli);
			if(max <= corr)
				max = corr;
		}
		return max+1;
	}
}

#endif /* TREE_H_ */
