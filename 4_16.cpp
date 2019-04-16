//1.https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
//方法一：开额外空间
vector<int>::iterator it = array.begin();
vector<int> v;
for (it; it != array.end();)
{
	if (*it % 2 != 0)
	{
		++it;
	}
	else
	{
		v.push_back(*it);
		it = array.erase(it);
	}
}
vector<int>::iterator i = v.begin();
for (i; i != v.end(); ++i)
{
	array.push_back(*i);
}
//方法二：插入排序思想
for (int i = 0; i<array.size(); ++i)
{
	if (array[i] % 2 == 0)
	{
		int tmp;
		for (int j = i; j<array.size(); ++j)
		{
			if (array[j] % 2 == 1)
			{
				tmp = array[j];
				while (j>i)
				{
					array[j] = array[j - 1];
					--j;
				}
				array[j] = tmp;
				++i;
			}
		}
		break;
	}
}

//2.https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		int count = 0;
		for (int i = 0; i<k - 1; ++i)
		{
			if (p1->next == NULL)
				return NULL;
			else
			{
				p1 = p1->next;
			}
		}
		while (p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
};
//3.https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	void _Convert(TreeNode* cur, TreeNode** pprev)
	{
		if (cur == NULL)
			return;
		_Convert(cur->left, pprev);


		cur->left = *pprev;
		if (*pprev)
			(*pprev)->right = cur;

		*pprev = cur;

		_Convert(cur->right, pprev);
	}

	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* prev = NULL;
		_Convert(pRootOfTree, &prev);

		TreeNode* head = pRootOfTree;
		while (head && head->left)
		{
			head = head->left;
		}

		return head;
	}
};

//4.https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
bool FindNode(struct TreeNode* root, struct TreeNode* node) {
	if (root == NULL)
		return false;

	if (root == node)
		return true;

	return FindNode(root->left, node)
		|| FindNode(root->right, node);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	if (root == NULL)
		return NULL;

	if (root == p || root == q)
		return root;

	bool pInLeft, pInRight, qInLeft, qInRight;
	if (FindNode(root->left, p)){
		pInLeft = true;
		pInRight = false;
	}
	else{
		pInRight = true;
		pInLeft = false;
	}

	if (FindNode(root->left, q)) {
		qInLeft = true;
		qInRight = false;
	}
	else {
		qInRight = true;
		qInLeft = false;
	}

	if (pInLeft && qInLeft){
		return lowestCommonAncestor(root->left, p, q);
	}
	else if (pInRight && qInRight){
		return lowestCommonAncestor(root->right, p, q);
	}
	else {
		return root;
	}
}
