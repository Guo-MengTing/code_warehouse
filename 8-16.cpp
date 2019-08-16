//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* cur=head;
        ListNode* next=NULL;
        while(cur!=NULL)
        {
            next=cur->next;
            while(cur&&next&&(cur->val==next->val))
            {
                next=next->next;
            }
            cur->next=next;
            cur=next;
        }
        return head;
    }
};

//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if (head==NULL||head->next==NULL){
            return head;
        }
        ListNode joke=ListNode(0);
        joke.next=head;
        ListNode *h=&joke;
        while(h->next&&h->next->next){
            bool pd=false;
            ListNode *n=h->next;
            while (n&&n->next&&n->val==n->next->val){
                n=n->next;
                pd=true;
            }
            if (pd){
                h->next=n->next;
            }else{
                h=h->next;
            }        
        }
        return joke.next;
    }
};
