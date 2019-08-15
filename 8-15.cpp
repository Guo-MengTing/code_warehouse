//https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
/*要新增一个节点在head前面，防止只有一个节点的情况*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* fast=newhead;
        ListNode* slow=newhead;
        while(n--)
        {
            fast=fast->next;
        }
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return newhead->next;
    }
};

//https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        RandomListNode* cur=pHead;
        while(cur)
        {
            RandomListNode* node=new RandomListNode(cur->label);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        cur=pHead;
        RandomListNode* p=NULL;
        while(cur)
        {
            p=cur->next;
            if(cur->random)
               {
                   p->random=cur->random->next;
               }
            cur=p->next;
        }
        RandomListNode* head=pHead->next;
        cur=pHead;
        RandomListNode* tmp=NULL;
        while(cur&&cur->next)
        {
            tmp=cur->next;
            cur->next=tmp->next;
            cur=tmp;
        }
        return head;
    }
};

//https://www.nowcoder.com/profile/221294738/codeBookDetail?submissionId=49506016
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index<7)
            return index;
        int p2=0,p3=0,p5=0;
        int minNum=1;
        vector<int> v;
        v.push_back(minNum);
        while(v.size()<index)
        {
            minNum=min(v[p2]*2,min(v[p3]*3,v[p5]*5));
            if(v[p2]*2==minNum)
                ++p2;
            if(v[p3]*3==minNum)
                ++p3;
            if(v[p5]*5==minNum)
                ++p5;
            v.push_back(minNum);
        }
        return minNum;
    }
};

//https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&tPage=3&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class listNode{
public:
    int val;
    listNode* next;
    listNode(int val)
    {
        this->val=val;
    }
};
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        listNode* head=new listNode(0);
        listNode* cur=head;
        listNode* tmp;
        for(int i=1;i<n;++i)
        {
            tmp=new listNode(i);
            cur->next=tmp;
            cur=tmp;
        }
        tmp->next=head;
        listNode* res;
        while(n>1)
        {
            res=head;
            for(int i=1;i<m-1;++i)
            {
                res=res->next;
            }
            res->next=res->next->next;
            head=res->next;
            --n;
        }
        return head->val;
    }
};
//https://leetcode-cn.com/problems/swap-nodes-in-pairs/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* newhead=new ListNode(0);
        ListNode* nh=newhead;
        ListNode* cur=head;
        while(cur&&cur->next)
        {
            nh->next=cur->next;
            cur->next=cur->next->next;
            nh=nh->next;
            cur=cur->next;
        }
        nh=newhead->next;
        cur=head;
        while(nh&&cur)
        {
            ListNode* next1=nh->next;
            ListNode* next2=cur->next;
            nh->next=cur;
            cur->next=next1;
            nh=next1;
            cur=next2;
        }
        if(cur)
            nh->next=cur;
        return newhead->next;
    }
};