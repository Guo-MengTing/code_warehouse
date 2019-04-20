//最长公共子序列（动态规划）
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	string s1;
	string s2;
	while (cin >> s1 >> s2)
	{
		string s ;
		int len1 = s1.size();
		int len2 = s2.size();
		vector<vector<int>> dp(len1,vector<int>(len2,0));
		if (s1[0] == s2[0])
			dp[0][0] = 1;
		else
			dp[0][0] = 0;
		for (int i = 1; i < len1; ++i)
		{
			if (s1[i] == s2[0])
				dp[i][0] = 1;
			else
				dp[i][0] = 0;
			dp[i][0] = max(dp[i - 1][0], dp[i][0]);
		}
		for (int j = 1; j < len2; ++j)
		{
			if (s1[0] == s2[j])
				dp[0][j] = 1;
			else
				dp[0][j] = 0;
			dp[0][j] = max(dp[0][j], dp[0][j - 1]);
		}
		for (int i = 1; i < len1; ++i)
		{
			for (int j = 1; j < len2; ++j)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
				if (s1[i] == s2[j])
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout<< dp[len1 - 1][len2 - 1]<<endl;
	}
}


//二叉树中序遍历
//递归
//C语言
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int GetSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void _inorderTraversal(struct TreeNode* root, int* array, int* index)
{
	if (root == NULL)
		return 0;
	_inorderTraversal(root->left, array, index);
	array[(*index)++] = root->val;
	_inorderTraversal(root->right, array, index);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetSize(root);               //计算二叉树的节点个数
	int* array = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_inorderTraversal(root, array, &index);
	return array;
}

//C++
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> v;
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL)
			return v;
		inorderTraversal(root->left);
		v.push_back(root->val);
		inorderTraversal(root->right);
		return v;
	}
};

//非递归
//利用栈结构
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		while (cur || !s.empty())
		{
			if (cur)
			{
				s.push(cur);              //如果cur不为空，入栈
				cur = cur->left;
			}
			else
			{
				cur = s.top();              //当cur为空，cur为栈顶元素
				v.push_back(cur->val);         //cur的左子树为空，将cur的值尾插进vector
				s.pop();
				cur = cur->right;
			}
		}
		return v;
	}
};

//后序遍历
//C语言
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int GetSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return GetSize(root->left) + GetSize(root->right) + 1;
}
void _postorderTraversal(struct TreeNode* root, int* array, int* index)
{
	if (root == NULL)
		return 0;
	_postorderTraversal(root->left, array, index);
	_postorderTraversal(root->right, array, index);
	array[(*index)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetSize(root);
	int* array = (int*)malloc(sizeof(int)*(*returnSize));
	int index = 0;
	_postorderTraversal(root, array, &index);
	return array;
}

//C++
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> v;
	vector<int> postorderTraversal(TreeNode* root) {
		if (root == NULL)
			return v;
		postorderTraversal(root->left);
		postorderTraversal(root->right);
		v.push_back(root->val);
		return v;
	}
};

//非递归
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> v;
		stack<TreeNode*> s;            //新建一个栈结构
		if (root == NULL)
			return v;
		TreeNode* prev = NULL;            //用prev记录上一个访问过的节点
		s.push(root);
		while (!s.empty())
		{
			TreeNode* cur = s.top();
			if ((cur->left == NULL&&cur->right == NULL) ||
				(prev != NULL && (prev == cur->left || prev == cur->right)))    //如果prev等于当前节点的子节点，则说明当前节点的左右节点都已经访问过
			{
				v.push_back(cur->val);
				prev = cur;                   //更新prev
				s.pop();
			}
			else
			{
				if (cur->right != NULL)              //如果右节点不为空，则入栈
					s.push(cur->right);
				if (cur->left != NULL)               //如果左节点不为空，也入栈
					s.push(cur->left);
			}
		}
		return v;
	}
};

//层序遍历
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;               //新建一个队列
		if (root == NULL)
			return res;
		q.push(root);                  //将根节点入队列
		while (!q.empty())
		{
			TreeNode* cur = q.front();
			int size = q.size();
			vector<int> v;
			while (size)
			{
				cur = q.front();
				v.push_back(cur->val);
				--size;
				if (cur->left)
					q.push(cur->left);        //如果cur左节点不为空则入队
				if (cur->right)
					q.push(cur->right);       //如果cur右节点不为空则入队
				q.pop();
			}
			res.push_back(v);

		}
		return res;
	}
};