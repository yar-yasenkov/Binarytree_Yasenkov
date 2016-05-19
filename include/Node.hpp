#ifndef A_H_INCLUDED 
#define A_H_INCLUDED

       

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
 TreeNode<T>::TreeNode() :data(0), left(nullptr), right(nullptr)
 {}
template <typename T>
TreeNode<T>::TreeNode(const T &a)
{
	data = a;
	left = right = nullptr;
}

template <typename T>
T TreeNode <T>::get_data()
{
	return data;
}
#endif
