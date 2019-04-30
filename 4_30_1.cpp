//1.https://www.nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//方法一：直接根据前序遍历得到中序遍历
#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s))
	{
		stack<char> st;
		int len = s.size();
		for (int i = 0; i < len; ++i)
		{
			if (s[i] != '#')
				st.push(s[i]);
			else
			{
				if (!st.empty())
				{
					cout << st.top();
					st.pop();
				}
			}
		}
		cout << endl;
	}
	return 0;
}

//方法二：先根据前序遍历构建二叉树，再进行中序遍历
#include<iostream>
#include<string>
using namespace std;
string s;
int i;
struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	char val;
	TreeNode(char c)
		:left(nullptr)
		, right(nullptr)
		, val(c)
	{}
};

TreeNode* TreeCreate()
{
	char c = s[i++];
	if (c== '#')
		return NULL;
	TreeNode* root = new TreeNode(c);
	root->left = TreeCreate();
	root->right = TreeCreate();
	return root;
}

void InorderTraversal(TreeNode* root)
{
	if (root == NULL)
		return;
	InorderTraversal(root->left);
	cout << root->val << ' ';
	InorderTraversal(root->right);
}

int main()
{
	while (getline(cin, s))
	{
		int i = 0;
		TreeNode* root = TreeCreate();
		InorderTraversal(root);
		cout << endl;
	}
}













