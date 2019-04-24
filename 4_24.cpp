//��ͬ����
class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL&&q == NULL)
			return true;
		if (p&&q && (p->val == q->val))
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
	}
};

//�Գƶ�����
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		return IsMirror(root, root);
	}
	bool IsMirror(TreeNode* p, TreeNode* q)
	{
		if (!p&&!q)
			return true;
		if (p&&q && (p->val == q->val))
		{
			return IsMirror(p->left, q->right) && IsMirror(p->right, q->left);
		}
		else
			return false;
	}
};

//��һ����������
class Solution {
public:
	bool isSubtree(TreeNode* s, TreeNode* t) {
		if (t == NULL)
			return true;
		if (s == NULL)
			return false;
		if (isSame(s, t))
			return true;
		else
			return isSubtree(s->left, t) || isSubtree(s->right, t);
	}
	bool isSame(TreeNode* s, TreeNode* t)
	{
		if (s == NULL || t == NULL)
		{
			if (!s&&!t)
				return true;
			else
				return false;
		}
		if (s&&t && (s->val == t->val))
			return isSame(s->left, t->left) && isSame(s->right, t->right);
		else return false;
	}
};

//���������
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL)
			return 0;
		queue<TreeNode*> q;
		q.push(root);
		vector<vector<int>> res;
		while (!q.empty())
		{
			int size = q.size();
			vector<int> v;
			while (size)
			{
				TreeNode* cur = q.front();
				v.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				q.pop();
				--size;
			}
			res.push_back(v);
		}
		return res.size();
	}
};

