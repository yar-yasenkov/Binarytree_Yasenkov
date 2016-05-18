
#include <iostream>
#include <fstream>
template <typename T> class Tree;
#include "Node.hpp"
using namespace std;

template <typename T>
class Tree
{
public:
                     /* âîçâðàùàåò óêàçàòåëü íà êîðåíü äåðåâà */
        class Exception
        {
                char* information;
                public:
        	Exception(char* err);
        	char* reason()
        	{
        		 return information;
        	}
        };
        
        class Already_exist : public Exception
        {
                public:
	        Already_exist();
        };

        class File_Not_Open : public Exception
        {
               public:
	       File_Not_Open();
        };

        class Empty_tree : public Exception
        {
               public:
	       Empty_tree();
         };

        class Element_not_found : public Exception
        {  
               public:
	       Element_not_found();
        };

        class Tree_Was_Deleted : public Exception
        {  
               public:
	       Tree_Was_Deleted();
        };
        
        Already_exist::Already_exist() : Exception("ERROR: element already exists!") {}
        File_Not_Open::File_Not_Open() : Exception("ERROR: file not open!") {}
        Empty_tree::Empty_tree() : Exception("ERROR: tree is empty!") {}
        Element_not_found::Element_not_found() : Exception("ERROR: this element does not exist!") {}
        Tree_Was_Deleted::Tree_Was_Deleted() : Exception("ERROR: tree is deleted!") {}
        Tree();                                                    /* êîíñòðóêòîð */
	bool insert_node(const T &) /*throw(Already_exist &)*/;                         /* âñòàâëÿåò óçåë */
	bool input(string) /*throw(File_Not_Open &)*/;
	bool output(TreeNode<T>*);
	bool inorder_walk(TreeNode<T>*) /*throw(Empty_tree &)*/;                    /* ïå÷àòàåò âñå êëþ÷è â íåóáûâàþùåì ïîðÿäêå */
	TreeNode<T>* find_node(TreeNode<T>*, const T &) /*throw(Element_not_found &)*/;
	TreeNode<T> *get_root() /*throw(Empty_tree &)*/;       
private:
	TreeNode<T> *root;                                  /* ñîáñòâåííî, ñàì êîðåíü */
};

template <typename T>
Tree<T>::Tree()
{
	root = 0;                      /* â íà÷àëå äåðåâî ïóñòî */
}

template <typename T>
bool Tree<T>::input(string name) /*throw(File_Not_Open &)*/
{
	T a;
	fstream fin;
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
		throw File_Not_Open();
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
TreeNode<T>* Tree<T>::find_node(TreeNode<T>* n,
	const T & val) /*throw(Element_not_found &)*/
{
	if (n == 0 || val == n->get_data())
		return n;
	if (val > n->get_data())
		return find_node(n->right, val);
	else
		return find_node(n->left, val);
       
	
}




template <typename T>
bool Tree<T>::insert_node(const T &x) /*throw(Already_exist &)*/
{
	TreeNode<T>* elem=nullptr;
	elem=find_node(root,x);
	if (elem!=nullptr) 
	{
		throw Already_exist();
	}
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
bool Tree<T>::inorder_walk(TreeNode<T>* n) /*throw (Empty_tree &)*/
{
	bool marker=false;
	if (n==0)
	{
		throw Empty_tree();
	}
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
