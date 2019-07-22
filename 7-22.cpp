//https://www.nowcoder.com/questionTerminal/445c44d982d04483b04a54f298796288
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
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> res;
            if(pRoot==NULL)
                return res;
            TreeNode* cur=pRoot;
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                int size=q.size();
                cur=q.front();
                vector<int> v;
                while(size--)
                {
                    cur=q.front();
                    v.push_back(cur->val);
                    if(cur->left)
                        q.push(cur->left);
                    if(cur->right)
                        q.push(cur->right);
                    q.pop();
                }
                res.push_back(v);
            }
            return res;
        }
    
};

//数据库连接个数
#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	string id, op;
	int max, pool;
	while (cin >> n)
	{
		max = 0;
		pool = 0;
		while (n--)
		{
			cin >> id >> op;
			if (op[0] == 'c'&&++pool > max)
				max = pool;
			if (op[0] == 'd')
				--pool;
		}
		cout << max << endl;
	}
}



