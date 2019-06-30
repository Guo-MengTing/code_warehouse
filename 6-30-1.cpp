//https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    struct ListNode* head,*tail;
    if(l1->val < l2->val)
    {
        head=l1;
        l1=l1->next;
    }
    else
    {
        head=l2;
        l2=l2->next;
    }
    tail=head;
    while(l1!=NULL && l2!=NULL)
    {
        if(l1->val < l2->val)
        {
            tail->next=l1;
            l1=l1->next;
        }
        else
        {
            tail->next=l2;
            l2=l2->next;
        }
        tail=tail->next;
    }
    if(l1!=NULL)
        tail->next=l1;
    if(l2!=NULL)
        tail->next=l2;
    return head;
}

//https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead==NULL)
            return NULL;
        struct ListNode* lessHead,*lessTail,*greaterHead,*greaterTail;
        lessHead=lessTail=(struct ListNode*)malloc(sizeof(struct ListNode));
        greaterHead=greaterTail=(struct ListNode*)malloc(sizeof(struct ListNode));
        struct ListNode* cur=pHead;
        while(cur)
        {
            if(cur->val < x)
            {
                lessTail->next=cur;
                lessTail=lessTail->next;
            }
            else
            {
                greaterTail->next=cur;
                greaterTail=greaterTail->next;
            }
            cur=cur->next;
        }
        lessTail->next=greaterHead->next;
        pHead=lessHead->next;
        greaterTail->next=NULL;
        free(lessHead);
        free(greaterHead);
        return pHead;
    }
};