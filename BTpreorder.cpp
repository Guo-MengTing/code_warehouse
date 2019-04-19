//前序遍历
//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/submissions/
//递归（C语言）
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
int GetSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void _preorderTraversal(struct TreeNode* root, int *array, int* index)
{
	if (root == NULL)
		return 0;
	array[(*index)++] = root->val;
	_preorderTraversal(root->left, array, index);
	_preorderTraversal(root->right, array, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = GetSize(root);
	int* array = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_preorderTraversal(root, array, &index);
	return array;
}

//C++
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(NULL)
		, right(NULL)
	{}
};
class Solution
{
public:
	vector<int> v;
	vector<int> preorderTraversal(TreeNode* root)
	{
		if (root == NULL)
			return v;
		v.push_back(root->val);
		preorderTraversal(root->left);
		preorderTraversal(root->right);
		return v;
	}
}

//非递归
//利用栈结构
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x)
		:val(x)
		, left(NULL)
		, right(NULL)
	{}
};
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur || !s.empty())
		{
			if (cur)
			{
				s.push(cur);
				v.push_back(cur->val);
				cur = cur->left;
			}
			else
			{
				cur = s.top();       //cur为空时，找到它的父亲节点
				s.pop();
				cur = cur->right;        //遍历它的右节点
			}
		}
		return v;
	};
	