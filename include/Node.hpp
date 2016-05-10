#ifndef A_H_INCLUDED 
#define A_H_INCLUDED
 class TreeNode
{
	friend class Tree;
public:
	TreeNode();
	TreeNode(const int &);
	int get_data();
protected:
	TreeNode* left;           /* óêàçàòåëü íà ëåâîãî ðåáåíêà */
	TreeNode* right;          /* óêàçàòåëü íà ïðàâîãî ðåáåíêà */
	TreeNode* parent;         /* óêàçàòåëü íà ðîäèòåëÿ */
	int data;            /* êëþ÷ */
};

 TreeNode::TreeNode() :data(0), left(0), right(0)
 {}
TreeNode::TreeNode(const int &a)
{
	data = a;
	left = right = 0;
}

int TreeNode::get_data()
{
	return data;
}
#endif
