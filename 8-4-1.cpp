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