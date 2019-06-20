//https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    void _Convert(TreeNode* cur,TreeNode*& prev)
    {
        if(cur==NULL)
            return ;
        _Convert(cur->left,prev);
        cur->left=prev;
        if(prev!=NULL)
            prev->right=cur;
        prev=cur;
        _Convert(cur->right,prev);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode* prev=NULL;
        TreeNode* cur=pRootOfTree;
        _Convert(cur,prev);
        while(cur&&cur->left)
        {
            cur=cur->left;
        }
        return cur;
    }
};

//https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
    vector<vector<int>> res;
    vector<int> path;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)
            Find(root,expectNumber);
        return res;
        
    }
    void Find(TreeNode* root,int expectNumber)
    {
        int num=expectNumber;
        path.push_back(root->val);
        if(num-root->val==0&&!root->left&&!root->right)
        {
            res.push_back(path);
        }
        else
        {
            if(root->left)
            {
                Find(root->left,num-root->val);
            }
            if(root->right)
            {
                Find(root->right,num-root->val);
            }
        }
        path.pop_back();
    }
};