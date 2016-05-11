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

 TreeNode::TreeNode() :data(0), left(0), right(0)
 {}
TreeNode::TreeNode(const T &a)
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
