//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

//https://leetcode-cn.com/problems/balanced-binary-tree/
*Definition for a binary tree node.
* struct TreeNode {
	*int val;
	*struct TreeNode *left;
	*struct TreeNode *right;
	*
};
*/
int _maxDepth(struct TreeNode* root);

int _maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (root == NULL)
		return true;

	int leftDepth = _maxDepth(root->left);
	int rightDepth = _maxDepth(root->right);
	return abs(leftDepth - rightDepth) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}

bool _isBalanced(struct TreeNode* root, int* pDepth) {
	if (root == NULL) {
		*pDepth = 0;
		return true;
	}

	int leftDepth = 0, rightDepth = 0;
	if (_isBalanced(root->left, &leftDepth)
		&& _isBalanced(root->right, &rightDepth)
		&& abs(leftDepth - rightDepth) < 2)
	{
		*pDepth = leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
		return true;
	}
	else
	{
		return false;
	}

}

bool isBalanced(struct TreeNode* root) {
	int depth = 0;
	return _isBalanced(root, &depth);
}

//https://leetcode-cn.com/problems/same-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;

	return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
}

//https://leetcode-cn.com/problems/symmetric-tree/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool _isSymmetric(struct TreeNode* left, struct TreeNode* right) {
	if (left == NULL&&right == NULL)
		return true;
	if (left == NULL || right == NULL)
		return false;

	return (left->val == right->val) && _isSymmetric(left->left, right->right) && _isSymmetric(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (root == NULL)
		return true;

	return _isSymmetric(root->left, root->right);
}