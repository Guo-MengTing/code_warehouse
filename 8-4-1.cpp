//https://www.nowcoder.com/questionTerminal/e08819cfdeb34985a8de9c4e6562e724
方法一：递归
class Solution {
public:
    int run(TreeNode *root) {
       if(root==NULL)
           return 0;
        if(root->left==NULL)
            return run(root->right)+1;
        if(root->right==NULL)
            return run(root->left)+1;
        int leftlength=run(root->left)+1;
        int rightlength=run(root->right)+1;
        if(leftlength>=rightlength)
            return rightlength;
        else
            return leftlength;
	}
};
方法二：非递归（层序遍历，找第一个叶子节点）
class Solution {
public:
    int run(TreeNode *root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        int count=0;
        while(!q.empty())
        {
            ++count;
            int size=q.size();
            while(size--)
            {
                cur=q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                if(cur->left==NULL&&cur->right==NULL)
                    return count;
                q.pop();
            }
        }
        return count;
    }
};

//https://www.nowcoder.com/questionTerminal/22f9d7dd89374b6c8289e44237c70447
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
       stack<int> st;
       for(int i=0;i<tokens.size();++i)
       {
           if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
           {
               if(st.size()<2)
                   return 0;
               int a,b,res;
               b=st.top();
               st.pop();
               a=st.top();
               st.pop();
               if(tokens[i]=="+")
                   res=a+b;
               if(tokens[i]=="-")
                   res=a-b;
               if(tokens[i]=="*")
                   res=a*b;
               if(tokens[i]=="/")
                   res=a/b;
               st.push(res);
           }
        else
        {
            int tmp=atoi(tokens[i].c_str());
            st.push(tmp);
        }
       }
        if(st.size()==1)
            return st.top();
        else
            return 0;
    }
};