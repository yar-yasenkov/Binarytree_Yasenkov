#ifndef A_H_INCLUDED 
#define A_H_INCLUDED

        Already_exist::Already_exist() : Exception("ERROR: element already exists!") {}
        File_Not_Open::File_Not_Open() : Exception("ERROR: file not open!") {}
        Empty_tree::Empty_tree() : Exception("ERROR: tree is empty!") {}
        Element_not_found::Element_not_found() : Exception("ERROR: this element does not exist!") {}
        Tree_Was_Deleted::Tree_Was_Deleted() : Exception("ERROR: tree is deleted!") {}


template <typename T> class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode();
	TreeNode(const T &);
	T get_data();
protected:
	TreeNode* left;           /* óêàçàòåëü íà ëåâîãî ðåáåíêà */
	TreeNode* right;          /* óêàçàòåëü íà ïðàâîãî ðåáåíêà */
	TreeNode* parent;         /* óêàçàòåëü íà ðîäèòåëÿ */
	T data;            /* êëþ÷ */
};

template <typename T>
 TreeNode<T>::TreeNode() :data(0), left(0), right(0)
 {}
template <typename T>
TreeNode<T>::TreeNode(const T &a)
{
	data = a;
	left = right = 0;
}

template <typename T>
T TreeNode <T>::get_data()
{
	return data;
}
#endif
