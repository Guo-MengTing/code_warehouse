//https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
       vector<int> v;
       queue<TreeNode*> q;
        if(root==NULL)
            return v;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            int size=q.size();
            while(size--)
            {
                cur=q.front();
                v.push_back(cur->val);
                if(cur->left!=NULL)
                    q.push(cur->left);
                if(cur->right!=NULL)
                    q.push(cur->right);
                q.pop();
            }
        }
        return v;
    }
};

//https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> st;
        int j=0;
        for(int i=0;i<pushV.size();++i)
        {
            st.push(pushV[i]);
            while(!st.empty()&&st.top()==popV[j])
            {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};

//https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    void push(int value) {
        st.push(value);
        if(mst.empty()||value<=mst.top())
            mst.push(value);
    }
    void pop() {
        if(st.top()==mst.top())
        {
            st.pop();
            mst.pop();
        }
        else
            st.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return mst.top();
    }
private:
    stack<int> st;
    stack<int> mst;
};

//https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> res;
        if(matrix.size()==0)
            return res;
       int h=0;
        int he=row-1;
       int s=0;
        int se=col-1;
        while(h<=he&&s<=se)
        {
            for(int i=h;i<=he;++i)
                res.push_back(matrix[h][i]);
            for(int i=s+1;i<=se;++i)
                res.push_back(matrix[i][se]);
            if(s!=se)
            for(int i=he-1;i>=0;--i)
                res.push_back(matrix[se][i]);
            if(h!=he)
            for(int i=se-1;i>h;--i)
                res.push_back(matrix[i][h]);
        }
        return res;
    }
    
};

//https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==NULL)
            return;
        TreeNode* tmp;
        tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

//https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
lass Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1!=NULL&&pRoot2!=NULL)
        {
            if(ispart(pRoot1,pRoot2))
                return true;
            if(HasSubtree(pRoot1->left,pRoot2))
                return true;
            if(HasSubtree(pRoot1->right,pRoot2))
                return true;
        }
        return false;
    }
    bool ispart(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2==NULL)
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        else
           return (ispart(pRoot1->left,pRoot2->left)&&ispart(pRoot1->right,pRoot2->right));
    }
};
