 class TreeNode
{
	friend class Tree;
public:
	TreeNode();
	TreeNode(const int &);
	int get_data();
protected:
	TreeNode* left;           /* ��������� �� ������ ������� */
	TreeNode* right;          /* ��������� �� ������� ������� */
	TreeNode* parent;         /* ��������� �� �������� */
	int data;            /* ���� */
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