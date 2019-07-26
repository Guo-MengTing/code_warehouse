//https://leetcode-cn.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        int tmp=0;
        while(l1||l2||tmp)
        {
            int sum=0;
            if(l1!=NULL)
                sum+=l1->val;
            if(l2!=NULL)
                sum+=l2->val;
            sum+=tmp;
            tmp=sum/10;
            sum%=10;
            ListNode* next=l1?l1:l2;
            if(next==NULL)
                next=new ListNode(sum);
            next->val=sum;
            
            cur->next=next;
            cur=cur->next;
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        return head->next;
    }
};

//https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<2)
            return s;
        int n=s.size();
        string res="";
        bool flag=false;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int maxlen=0;
        for(int r=1;r<n;++r)
        {
            for(int l=0;l<r;++l)
            {
                if((s[l]==s[r])&&((r-l)<=2||dp[l+1][r-1]))
                {
                    dp[l][r]=true;
                    flag=true;
                    if((r-l+1>maxlen))
                    {
                        maxlen=r-l+1;
                        res=s.substr(l,r-l+1);
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

//https://leetcode-cn.com/problems/reverse-integer/submissions/
class Solution {
public:
    int reverse(int x) {
        int sum=0;
        while(x)
        {
            int tmp=x%10;
            x/=10;
            if((sum>INT_MAX/10)||((sum==INT_MAX/10)&&tmp>7))
                return 0;
            if((sum<INT_MIN/10)||((sum==INT_MIN/10)&&tmp<-8))
                return 0;
            sum=sum*10+tmp;
        }
        return sum;
    }
};

//https://leetcode-cn.com/problems/palindrome-number/submissions/
class Solution {
public:
    bool isPalindrome(int x) {
        int tmp=x;
        long long sum=0;
        if(x<0)
            return false;
        while(tmp)
        {
            sum=sum*10+tmp%10;
            tmp/=10;
        }
        if(sum==x)
            return true;
        else
            return false;
    }
};