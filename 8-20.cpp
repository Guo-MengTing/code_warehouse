//https://leetcode-cn.com/problems/insertion-sort-list/submissions/
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* newhead=new ListNode(0);
        newhead->next=head;
        ListNode* prev=head;
        ListNode* cur=head->next;
        while(cur)
        {
            if(cur->val>=prev->val)
            {
                cur=cur->next;
                prev=prev->next;
            }
            else
            {
                prev->next=cur->next;
                ListNode* t1=newhead;
                ListNode* t2=newhead->next;
                while(cur->val>t2->val)
                {
                    t1=t1->next;
                    t2=t2->next;
                }
                t1->next=cur;
                cur->next=t2;
                cur=prev->next;
            }
        }
        return newhead->next;   
    }
};

//https://leetcode-cn.com/problems/sort-list/submissions/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* mid=GetMid(head);
        ListNode* newhead=mid->next;
        mid->next=NULL;
        return mergesort(sortList(head),sortList(newhead));
    }
    ListNode* GetMid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* mergesort(ListNode* h1,ListNode* h2)
    {
        ListNode* newhead=new ListNode(0);
        ListNode* cur=newhead;
        while(h1&&h2)
        {
            if(h1->val<=h2->val)
            {
                cur->next=h1;
                h1=h1->next;
            }
            else
            {
                cur->next=h2;
                h2=h2->next;
            }
            cur=cur->next;
        }
        if(h1)
            cur->next=h1;
        else
            cur->next=h2;
        return newhead->next;
    }
};

//https://leetcode-cn.com/problems/palindrome-linked-list/submissions/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next&&fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* right=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        ListNode* cur=right;
        while(cur)
        {
            ListNode* next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        while(head&&prev)
        {
            if(head->val!=prev->val)
                return false;
            else
            {
                head=head->next;
                prev=prev->next;
            }
        }
        if(head==NULL||head->next==NULL)
            return true;
        return false;
    }
};

//https://leetcode-cn.com/problems/odd-even-linked-list/submissions/
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* pre=head;
        ListNode* cur=head->next;
        while(cur&&cur->next)
        {
            ListNode* tmp=pre->next;
            pre->next=cur->next;
            cur->next=cur->next->next;
            pre->next->next=tmp;
            pre=pre->next;
            cur=cur->next;
        }
        return head;
    }
};