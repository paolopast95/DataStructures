/*
 * test.cpp
 *
 *  Created on: 30 nov 2016
 *      Author: Paolo
 */


#include<stdlib.h>
#include "treeList.h"

int main(){

	treeList<char> Tree, TreeCop;

	treeList<char>::node n;
	Tree.insRoot();
	Tree.writeNode(Tree.root(),'a');

	Tree.insFirst(Tree.root(), 'b');
	Tree.insFirst(Tree.root(), 'c');

	n = Tree.root();
	n = Tree.firstChild(n);

	Tree.ins(n, 'd');

	n = Tree.root();
	n = Tree.firstChild(n);
	Tree.insFirst(n, 'e');
	Tree.insFirst(n, 'f');

	Tree.print();

	n = Tree.firstChild(Tree.root());
	TreeCop.insRoot();
	TreeCop.writeNode(TreeCop.root(),'x');

	TreeCop.insFirst(TreeCop.root(), 'y');
	TreeCop.insFirst(TreeCop.root(), 'z');
	TreeCop.print();
	Tree.insSubTree(n, TreeCop);
	Tree.print();
	system("PAUSE");
	return 0;
}
