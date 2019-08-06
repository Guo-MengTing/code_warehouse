//https://www.nowcoder.com/practice/60e43001345241ba9266cb4ee6fc6350?tpId=46&tqId=29042&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head==NULL)
            return NULL;
        RandomListNode* cur=head;
        while(cur)
        {
            RandomListNode* node=new RandomListNode(cur->label);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        cur=head;
        RandomListNode* tmp=NULL;
        while(cur)
        {
            tmp=cur->next;
            if(cur->random)
            {
                tmp->random=cur->random->next;
            }
            cur=tmp->next;
        }
        cur=head;
        RandomListNode* newhead=head->next;
        tmp=NULL;
        while(cur!=NULL&&cur->next!=NULL)
        {
            tmp=cur->next;
            cur->next=tmp->next;
            cur=tmp;
        }
        return newhead;
    }
};
//https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.size()<1)
            return false;
        int len=s.size();
        vector<bool> dp(len+1,false);
        dp[0]=true;
        for(int i=1;i<=len;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(dp[j]==true&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

//https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9?tpId=46&tqId=29039&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)
            return false;
        ListNode* fast=head;
        ListNode* slow=head;
        bool flag=false;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=true;
                break;
            }
        }
        if(flag)
            return true;
        else
            return false;
    }
};
//https://www.nowcoder.com/practice/6e630519bf86480296d0f1c868d425ad?tpId=46&tqId=29038&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=false;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                flag=true;
                break;
            }
        }
        if(flag==false)
            return NULL;
        else
        {
            ListNode* cur=head;
            while(cur!=NULL&&slow!=NULL)
            {
                if(slow==cur)
                    return slow;
                cur=cur->next;
                slow=slow->next;
            }
        }
    }
};