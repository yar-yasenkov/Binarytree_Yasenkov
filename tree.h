#include "node.h"
#include <iostream>
#include <fstream>
using namespace std;

class Tree
{
public:
	Tree();                                                    /* ����������� */
	
	int insert_node(const int &);                         /* ��������� ���� */
	void input(char[256]);
	void output(TreeNode*);
	void inorder_walk(TreeNode*);                    /* �������� ��� ����� � ����������� ������� */
	TreeNode* find_node(TreeNode*, const int &);
	TreeNode *get_root();                            /* ���������� ��������� �� ������ ������ */
private:
	TreeNode *root;                                  /* ����������, ��� ������ */
};


Tree::Tree()
{
	root = 0;                      /* � ������ ������ ����� */
}


void Tree::input(char name[256])
{

	char fulpath[256] = "D:\\labiu8\\2 ���\\Binarysearchtree\\Debug\\";
	int a;
	fstream fin;
	strcat_s(fulpath, name);
	fin.open(fulpath, ios::in);//�������� �����
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
	TreeNode* n = new TreeNode(x);  /* ������� ����� ����, ��� �� ����� ��������� */
	TreeNode* ptr;
	TreeNode* ptr1 = 0;
	n->parent = n->left = n->right = 0;          /* �� - ���� */
	ptr = root;
	while (ptr != 0)                     /* ���� �� ����� � ���� ���������� ����� ��� ������ ������ ��������, ��� ������ ���� �������� */
	{
		ptr1 = ptr;                 /* ������� �������� ������ ���� */
		if (x < ptr->get_data())  /* �� ����������� ������ ������ - ����� �������� ����� ������ ��������, */
			ptr = ptr->left;
		else
			ptr = ptr->right;   /* ������ - ������ */
	}
	n->parent = ptr1;
	if (ptr1 == 0)                       /* ������ ���� �����? */
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

/* �������� ��� ������ - ���� � z ��� �����, �� �������� 0 � ��������������� ����
* �������� z, ���� � z ���� ���� �������, �� ����� �������� z, �������� ��� �������� �������� �
* ��� ��������. ���� �� ����� ����, �� ��������� ��������� �������������: �� ������� ���������
* (� ������ ������� �� ������) �� z ������� y; � ���� ��� ������ ������� (������). ������ �����
* ����������� ���� � �������������� ������ �� ������� y � ������� z, � ���� ������� y �������
* ��������� ���� �������� */



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