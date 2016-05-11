
#include <iostream>
#include <fstream>
template <typename T> class Tree;
#include "Node.hpp"
using namespace std;

template <typename T>
class Tree
{
public:
	Tree();                                                    /* êîíñòðóêòîð */
	
	bool insert_node(const T &);                         /* âñòàâëÿåò óçåë */
	bool input(string);
	bool output(TreeNode<T>*);
	bool inorder_walk(TreeNode<T>*);                    /* ïå÷àòàåò âñå êëþ÷è â íåóáûâàþùåì ïîðÿäêå */
	TreeNode<T>* find_node(TreeNode<T>*, const T &);
	TreeNode<T> *get_root();                            /* âîçâðàùàåò óêàçàòåëü íà êîðåíü äåðåâà */
        class Exept
        {
        	public:
        	void reportfile()
        	{
        		cout << "This value does not exist" << endl;
			return ;
        	}
        	
        	
        };
private:
	TreeNode<T> *root;                                  /* ñîáñòâåííî, ñàì êîðåíü */
};

template <typename T>
Tree<T>::Tree()
{
	root = 0;                      /* â íà÷àëå äåðåâî ïóñòî */
}

template <typename T>
bool Tree<T>::input(string name)
{
        
	//char fulpath[256] = "D:\\labiu8\\2 ñåì\\Binarysearchtree\\Debug\\";
	T a;
	fstream fin;
	//strcat_s(fulpath, name);
	fin.open(name, ios::in);//îòêðûòèå ôàéëà
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> a;
			insert_node(a);
		}
	}
	else 
	{
		return false;
	}
	fin.close();
	return true;
}

template <typename T>
bool Tree<T>::output(TreeNode<T>* n)
{
	bool marker=false;
	ofstream fout;
	fout.open("out.txt");
	if (n != 0)
	{
		inorder_walk(n->left);
		fout << n->get_data() << endl;
		inorder_walk(n->right);
	        marker=true;
	}
	fout.close();
	return marker;
}

template <typename T>
bool Tree<T>::insert_node(const T &x)
{
	TreeNode<T>* n = new TreeNode<T>(x);  
	TreeNode<T>* ptr;
	TreeNode<T>* ptr1 = 0;
	n->parent = n->left = n->right = 0;          
	ptr = root;
	while (ptr != 0)                     
	{
		ptr1 = ptr;                 
		if (x < ptr->get_data())  
			ptr = ptr->left;
		else
			ptr = ptr->right;  
	}
	n->parent = ptr1;
	if (ptr1 == 0)                      
		root = n;
	else
	{
		if (x < ptr1->get_data())
			ptr1->left = n;
		else
			ptr1->right = n;
	}
	return true;
}

template <typename T>
TreeNode<T>* Tree<T>::find_node(TreeNode<T>* n,
	const T & val)
{
	if (n == 0 || val == n->get_data())
		return n;
	if (val > n->get_data())
		return find_node(n->right, val);
	else
		return find_node(n->left, val);
}

template <typename T>
bool Tree<T>::inorder_walk(TreeNode<T>* n)
{
	bool marker=false;
	if (n != 0)
	{
		inorder_walk(n->left);
		cout << n->get_data() << endl;
		inorder_walk(n->right);
		marker=true;
	}
	return marker;
}

template <typename T>
TreeNode<T>* Tree<T>::get_root()
{
	return root;
}
