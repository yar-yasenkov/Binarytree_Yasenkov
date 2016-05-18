
#include <iostream>
#include <fstream>
template <typename T> class Tree;
#include "Node.hpp"
using namespace std;



int markerint=0;
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
Exception::Exception(char* _err) : information(_err){}        
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

Already_exist::Already_exist() : Exception("ERROR: this element already exists") {}
File_Not_Open::File_Not_Open() : Exception("ERROR: file not open!") {}
Empty_tree::Empty_tree() : Exception("ERROR:tree is empty!") {}
Element_not_found::Element_not_found() : Exception("ERROR: this element doe not exist!") {}
Tree_Was_Deleted::Tree_Was_Deleted() : Exception("ERROR: tree was deleted!") {}

        


template <typename T>
class Tree
{
public:
                     /* âîçâðàùàåò óêàçàòåëü íà êîðåíü äåðåâà */
   
       
        
     
        Tree();                                                    /* êîíñòðóêòîð */
	bool insert_node(const T &);                         /* âñòàâëÿåò óçåë */
	bool input(string);
	bool output(TreeNode<T>*);
	bool inorder_walk(TreeNode<T>*);                    /* ïå÷àòàåò âñå êëþ÷è â íåóáûâàþùåì ïîðÿäêå */
	TreeNode<T>* find_node(TreeNode<T>*, const T &);
	TreeNode<T> *get_root();       
        friend ostream & operator<< <>(ostream &out, Tree<T> &);
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
	if (n==0)
        {
        	throw Empty_tree();
        }
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
bool Tree<T>::insert_node(const T &x) 
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
	markerint=0;
	return marker;
}

template <typename T>
TreeNode<T>* Tree<T>::get_root()
{
	return root;
}

template <typename T>
ostream & operator <<(ostream &out, Tree<T> &tree)
{
	TreeNode<T> n=tree.get_root();
	if (tree.get_root()!=0)
	{
		inorder_walk(n->left);
		cout << n->get_data() << endl;
		inorder_walk(n->right);
		return out;
	}
	else throw Empty_tree();
}
