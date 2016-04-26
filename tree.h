#include "node.h"
#include <iostream>
#include <fstream>
using namespace std;

class Tree
{
public:
	Tree();                                                    /* конструктор */
	
	int insert_node(const int &);                         /* вставляет узел */
	void input(char[256]);
	void output(TreeNode*);
	void inorder_walk(TreeNode*);                    /* печатает все ключи в неубывающем порядке */
	TreeNode* find_node(TreeNode*, const int &);
	TreeNode *get_root();                            /* возвращает указатель на корень дерева */
private:
	TreeNode *root;                                  /* собственно, сам корень */
};


Tree::Tree()
{
	root = 0;                      /* в начале дерево пусто */
}


void Tree::input(char name[256])
{

	char fulpath[256] = "D:\\labiu8\\2 сем\\Binarysearchtree\\Debug\\";
	int a;
	fstream fin;
	strcat_s(fulpath, name);
	fin.open(fulpath, ios::in);//открытие файла
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> a;
			insert_node(a);
		}
	}
	fin.close();
}

void Tree::output(TreeNode* n)
{
	ofstream fout;
	fout.open("out.txt");
	if (n != 0)
	{
		inorder_walk(n->left);
		fout << n->get_data() << endl;
		inorder_walk(n->right);
	}
	fout.close();
}


int Tree::insert_node(const int &x)
{
	TreeNode* n = new TreeNode(x);  /* создаем новый узел, его мы будем вставлять */
	TreeNode* ptr;
	TreeNode* ptr1 = 0;
	n->parent = n->left = n->right = 0;          /* он - лист */
	ptr = root;
	while (ptr != 0)                     /* идем от корня и ищем подходящее место для нашего нового элемента, оно должно быть свободно */
	{
		ptr1 = ptr;                 /* будущий родитель нового узла */
		if (x < ptr->get_data())  /* по определению нашего дерева - слева значение ключа меньше родителя, */
			ptr = ptr->left;
		else
			ptr = ptr->right;   /* справа - больше */
	}
	n->parent = ptr1;
	if (ptr1 == 0)                       /* дерево было пусто? */
		root = n;
	else
	{
		if (x < ptr1->get_data())
			ptr1->left = n;
		else
			ptr1->right = n;
	}
	return 0;
}

/* возможны три случая - если у z нет детей, то помещаем 0 в соответствующее поле
* родителя z, если у z есть один ребенок, то можно вырезать z, соединив его родителя напрямую с
* его ребенком. Если же детей двое, то требуются некоторые приготовления: мы находим следующий
* (в смысле порядка на ключах) за z элемент y; у него нет левого ребенка (всегда). Теперь можно
* скопировать ключ и дополнительные данные из вершины y в вершину z, а саму вершину y удалить
* описанным выше способом */



TreeNode* Tree::find_node(TreeNode* n,
	const int & val)
{
	if (n == 0 || val == n->get_data())
		return n;
	if (val > n->get_data())
		return find_node(n->right, val);
	else
		return find_node(n->left, val);
}

void Tree::inorder_walk(TreeNode* n)
{
	if (n != 0)
	{
		inorder_walk(n->left);
		cout << n->get_data() << endl;
		inorder_walk(n->right);
	}
}


TreeNode* Tree::get_root()
{
	return root;
}