//https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
class Solution {
public:
    int Sum_Solution(int n) {
        int sum=n;
        bool flag=(n>0)&&(sum+=Sum_Solution(--n));
        return sum;
    }
};

//https://www.nowcoder.com/questionTerminal/9023a0c988684a53960365b889ceaf5e
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) { 
    }
};
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        TreeLinkNode* cur=pNode;
        if(cur->right!=NULL)
        {
            cur=cur->right;
            while(cur->left!=NULL)
                cur=cur->left;
            return cur;
        }
        while(cur->next!=NULL)
        {
            TreeLinkNode* pRoot=cur->next;
            if(pRoot->left==pNode)
                return pRoot;
            return pNode;
        }
        return NULL;
    }
};

//https://www.nowcoder.com/questionTerminal/ef068f602dde4d28aab2b210e859150a
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k==0)
            return NULL;
        stack<TreeNode*> st;
        TreeNode* cur=pRoot;
        vector<TreeNode*> v;
        while(cur||!st.empty())
        {
            if(cur)
            {
                st.push(cur);
                cur=cur->left;
            }
            else
            {
                cur=st.top();
                v.push_back(cur);
                st.pop();
                cur=cur->right;
            }
        }
        if(v.size()<k)
            return NULL;
        return v[k-1];
    }
};

//https://www.nowcoder.com/profile/644033/codeBookDetail?submissionId=1513179
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        return _isSymmetrical(pRoot,pRoot);
    }
    bool _isSymmetrical(TreeNode* p1,TreeNode* p2)
    {
        if(p1==NULL&&p2==NULL)
            return true;
        if(p1==NULL||p2==NULL)
            return false;
        if(p1->val!=p2->val)
            return false;
        return _isSymmetrical(p1->left,p2->right)&&_isSymmetrical(p1->right,p2->left);
    }

};