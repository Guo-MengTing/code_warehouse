//https://www.nowcoder.com/practice/152bc6c5b14149e49bf5d8c46f53152b?tpId=46&tqId=29034&rp=1&ru=%2Fta%2Fleetcode&qru=%2Fta%2Fleetcode%2Fquestion-ranking&tPage=1
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode* newhead=new ListNode(0);
        ListNode* cur=head;
        ListNode* pre=newhead;
        ListNode* next=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            pre=newhead;
            while(pre->next!=NULL&&pre->next->val<cur->val)
            {
                pre=pre->next;
            }
            cur->next=pre->next;
            pre->next=cur;
            cur=next;
        }
        return newhead->next;
    }  
};

//https://www.nowcoder.com/practice/3d281dc0b3704347846a110bf561ef6b?tpId=46&tqId=29037&rp=1&ru=%2Fta%2Fleetcode&qru=%2Fta%2Fleetcode%2Fquestion-ranking&tPage=1
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newhead=slow->next;
        slow->next=NULL;
        ListNode* prev=NULL;
        while(newhead)
        {
            ListNode* next=newhead->next;
            newhead->next=prev;
            prev=newhead;
            newhead=next;
        }
        ListNode* n1=NULL;
        ListNode* n2=NULL;
        newhead=prev;
        ListNode* cur=head;
        while(cur!=NULL&&newhead!=NULL)
        {
            n1=cur->next;
            n2=newhead->next;
            cur->next=newhead;
            cur=n1;
            newhead->next=cur;
            newhead=n2;
        }
    }
};