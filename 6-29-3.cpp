//https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
       if(pRoot==NULL)
           return true;
        int left=Height(pRoot->left);
        int right=Height(pRoot->right);
        if((left>right+1)||(left+1<right))
            return false;
        return IsBalanced_Solution(pRoot->left)&&IsBalanced_Solution(pRoot->right);
    }
    int Height(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        return max(Height(pRoot->left)+1,Height(pRoot->right)+1);
    }
};