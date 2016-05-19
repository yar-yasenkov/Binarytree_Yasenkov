#include <iostream>
#include <fstream>
template <typename T> class Tree;
#include "Node.hpp"
using namespace std;


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
        
        Tree();                                                    /* êîíñòðóêòîð */
	TreeNode<T>* find_node(TreeNode<T>*, const T &) const;
	bool search(TreeNode<T>*,const  T  &) const;
	bool insert_node(const T &);                         /* âñòàâëÿåò óçåë */
	bool input(const string &);
	bool output(TreeNode<T>*) const;
	bool inorder_walk(TreeNode<T>*) const;                    /* ïå÷àòàåò âñå êëþ÷è â íåóáûâàþùåì ïîðÿäêå */
	TreeNode<T> *get_root() const;       
        int get_numbernodes() const;
        TreeNode<T>* delete_node(TreeNode<T> *);  
        friend ostream & operator<< (ostream &out,const Tree<T> & tree)
        {
	TreeNode<T>* roottree=tree.get_root();
	if (roottree!=nullptr)
	{
		inorder_walk(roottree->left);
		cout << roottree->get_data() << endl;
		inorder_walk(roottree->right);
		return out;
	}
	else throw Empty_tree();
        }
        friend ifstream & operator>> (ifstream &fin, Tree<T> & tree)
        {
	if (!fin.is_open())
	{
	     throw File_Not_Open();
	}
	T x;
	while (!fin.eof())
	{
		if (fin>>x)
		{
			tree.insert_node(x);
		}
		else break;
	}
	return fin;
        }
       
       
private:
	
	TreeNode<T>* find_max(TreeNode<T>*) const;                                                                  
        TreeNode<T>* find_min(TreeNode<T>*) const;
	TreeNode<T> *root;                                  /* ñîáñòâåííî, ñàì êîðåíü */
	int number;
	 friend void increase_number (Tree<T> & tree)
        {
        	tree.number++;
        }
};
        
        
template <typename T>
Tree<T>::Tree()
{
	root = nullptr;                      /* â íà÷àëå äåðåâî ïóñòî */
	number=0;
}

template <typename T>
bool Tree<T>::input(const string & name) 
{
	T a;
	fstream fin;
	fin.open(name, ios::in);//îòêðûòèå ôàéëà
	if (fin.is_open())
	{
		while (!fin.eof())
		{
	                if (fin >> a)
	                {
			    increase_number(*this);
			    insert_node(a);
	                }
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
bool Tree<T>::output(TreeNode<T>* n) const
{
	bool marker=false;
	if (n==nullptr)
        {
        	throw Empty_tree();
        }
	ofstream fout;
	fout.open("out.txt");
	if (n != nullptr)
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
bool Tree<T>::search(TreeNode<T>* n,const T & value) const
{
	if (n==nullptr)
	{
		return false;
	}
	if ( value == n->get_data())
	{
		return true;
	}
	if (value > n->get_data())
		return search(n->right, value);
	else
		return search(n->left, value);
	return false;	
	
}



template <typename T>
TreeNode<T>* Tree<T>::find_node(TreeNode<T>* n,
	const T & val) const
{
	if (n == nullptr || val == n->get_data())
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
	TreeNode<T>* ptr1 = nullptr;
	n->parent = n->left = n->right = nullptr;          
	ptr = root;
	while (ptr != nullptr)                     
	{
		ptr1 = ptr;                 
		if (x < ptr->get_data())  
			ptr = ptr->left;
		else
			ptr = ptr->right;  
	}
	n->parent = ptr1;
	if (ptr1 == nullptr)                      
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
bool Tree<T>::inorder_walk(TreeNode<T>* n) const
{
	bool marker=false;
	if (n != nullptr)
	{
		inorder_walk(n->left);
		cout << n->get_data() << endl;
		inorder_walk(n->right);
		marker=true;
	}
	return marker;
}

template <typename T>
TreeNode<T>* Tree<T>::get_root() const
{
	return root;
}

template <typename T>
int Tree<T>::get_numbernodes() const
{
	return number;
}


template <typename T>
TreeNode<T>* Tree<T>::find_max(TreeNode<T>* x) const
{
        while(x->right!=nullptr)                            
                x=x->right;
        return x;
}

template <typename T>
TreeNode<T>* Tree<T>::find_min(TreeNode<T>* x) const
{
        while(x->left!=nullptr)                             
                x=x->left;
        return x;
}

template<typename T>
TreeNode<T>* Tree<T>::delete_node(TreeNode<T> *z)
{
        TreeNode<T>* y;
        TreeNode<T>* x;
        if(z->left == nullptr || z->right == nullptr)               /* в этой и следующих двух строках ищем вершину y, которую мы потом вырежем из дерева. Это либо z, либо следующий за z */
                y=z;
        else
                {
                	TreeNode<T>* a=z;
                	if(a == nullptr)
                          y=nullptr;
                        if(a->right!=nullptr)                                                /* если у нее есть правые дети, то следующий элемент - минимальный в правом поддереве */
                          return find_min(a->right);
                        y=a->parent;
                        while(y!=nullptr && a == y->right)                                   /* иначе - идем вверх и ищем первый элемент, являющийся левымпотомком своего родителя */
                        {
                            a=y;
                            y=y->parent;
                        }
                }
        if(y->left!=nullptr)                                  /* x - указатель на существующего ребенка y или 0 если таковых нет */ 
                x=y->left;
        else
                x=y->right;
        if(x!=nullptr)                                        /* эта и следующие 9 строк - вырезание y */ 
                x->parent=y->parent;
        if(y->parent == nullptr)
                root=x;
        else
        {
                if (y== (y->parent)->left)
                        (y->parent)->left=x;
                else
                        (y->parent)->right=x;
        }
        if(y!=z)                                        /* если мы вырезали вершин, отличную от z, то ее данные перемещаем в z */
                z->data=y->get_data();
        return y;
}
