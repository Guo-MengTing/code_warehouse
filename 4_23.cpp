//模拟实现atoi函数(将字符串中的数字字符转化为整型数字)
#include<iostream>
#include<string>
using namespace std;
int my_atoi(string& s)
{
	bool flag = true;
	int n = 0;
	string::iterator it = s.begin();
	while (it != s.end())  //如果字符串前面有空格，则跳过
	{
		if (*it == ' ')
			++it;
		else
			break;
	}
	if (*it == '-')         //如果*it=='-',则说明可能是负数
	{
		flag = false;
		++it;
	}
	else if (*it == '+')
	{
		flag = true;
		++it;
	}
	else if (*it<'0' || *it>'9')      //如果第一个字符不是+，-,或者数字则返回0
		return 0;
	for (it; it != s.end() && *it >= '0'&&*it <= '9'; ++it)   //如果迭代器没有到达末尾，并且是数字字符则转化为对应                                                          的整型
	{
		n = n * 10 + *it - '0';
	}
	if (flag == false)
		return -n;
	else
		return n;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		cout << my_atoi(s) << endl;
	}
}

//最近公共祖先
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) {
			return root;
		}
		if (root == p || root == q) {
			return root;
		}
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		if (left != NULL && right != NULL) {
			return root;
		}
		else if (left != NULL) {
			return left;
		}
		else if (right != NULL) {
			return right;
		}
		return NULL;
	}
};

//括号匹配问题
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> s1;
		string::iterator it = s.begin();
		if (s.empty())
			return true;
		else{
			for (it; it != s.end(); ++it)
			{
				if ((*it == '(') || (*it == '{') || (*it == '['))
					s1.push(*it);
				else
				{
					if (s1.empty())
						return false;
					else
					{
						if ((*it == ')'&&s1.top() == '(') ||
							(*it == '}'&&s1.top() == '{') ||
							(*it == ']'&&s1.top() == '['))
						{
							s1.pop();
						}
						else
							return false;
					}
				}
			}
			if (s1.empty())
				return true;
			else
				return false;
		}
	}
};
