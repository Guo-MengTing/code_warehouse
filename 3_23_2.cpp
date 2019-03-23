//https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

#include<iostream>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}
void _preorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return 0;

	array[*pIndex] = root->val;
	++(*pIndex);
	_preorderTraversal(root->left, array, pIndex);
	_preorderTraversal(root->right, array, pIndex);

}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;

	_preorderTraversal(root, array, &index);
	return array;
}


//https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int GetTreeSize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	else
		return GetTreeSize(root->left) + GetTreeSize(root->right) + 1;
}

void _inorderTraversal(struct TreeNode* root, int* array, int* pIndex)
{
	if (root == NULL)
		return;

	_inorderTraversal(root->left, array, pIndex);

	array[*pIndex] = root->val;
	(*pIndex)++;

	_inorderTraversal(root->right, array, pIndex);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	*returnSize = GetTreeSize(root);
	int* array = (int*)malloc(*returnSize*sizeof(int));
	int index = 0;
	_inorderTraversal(root, array, &index);

	return array;
}

//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;

	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);

	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}