// Binarysearchtree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include "tree.h"
#include "stdlib.h"
using namespace std;
int main()
{
	int a;
	Tree intTree;           
	intTree.input("in.txt");
	cout << endl << "inorder_walk:" << endl;              /* обходим */
	intTree.inorder_walk(intTree.get_root());       /* вот для этого понадобился метод get_root() :-) */
	cout << "number:";
	cin >> a;
	intTree.insert_node(a);
	cout << endl << "inorder_walk:" << endl;              /* обходим */
	intTree.inorder_walk(intTree.get_root());
	system("pause");

}