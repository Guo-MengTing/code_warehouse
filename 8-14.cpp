https://leetcode-cn.com/problems/zigzag-conversion/submissions/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string res="";
        int len=s.size();
        vector<string> tmp(min(numRows,len));
        bool flag=false;
        int cur=0;
        for(int i=0;i<len;++i)
        {
            tmp[cur]+=s[i];
            if(cur==0||cur==numRows-1)
            {
                flag=!flag;
            }
            if(flag)
            {
                ++cur;
            }
            else
                --cur;
        }
        for(int i=0;i<tmp.size();++i)
        {
            res+=tmp[i];
        }
        return res;
    }
};

//https://leetcode-cn.com/problems/same-tree/submissions/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL)
            return true;
        return _isSame(p,q);
    }
    bool _isSame(TreeNode* p,TreeNode* q)
    {
        if(q==NULL&&p==NULL)
            return true;
        if(p&&q&&(p->val==q->val))
        {
            return _isSame(p->left,q->left)&&_isSame(p->right,q->right);
        }
        else
            return false;
    }
};

//https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        string res="";
        if(s.empty())
            return res;
        int n=s.size();
        bool flag=false;
        int maxlen=0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(s[i]==s[j]&&(i-j<=2||dp[j+1][i-1]))
                {
                    dp[j][i]=true;
                    flag=true;
                    if(i-j+1>maxlen)
                    {
                        maxlen=i-j+1;
                        res=s.substr(j,i-j+1);
                    }
                }
            }
        }
        if(flag)
            return res;
        else
        {
            res+=s[0];
            return res;
        }
	}
};

//https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
         unordered_set<char> st;
        int maxSum=0;
        int j=0;
        for(int i=0;i<s.size();++i)
        {
            while(st.find(s[i])!=st.end())
            {
                st.erase(s[j]);
                ++j;
            }
            maxSum=max(maxSum,i-j+1);
            st.insert(s[i]);
        }
        return maxSum;
        
    }
};