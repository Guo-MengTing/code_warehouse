//https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* cur=pHead;
        if(pHead==NULL)
            return NULL;
        while(cur)
        {
            RandomListNode* node=new RandomListNode(cur->label);
            node->next=cur->next;
            cur->next=node;
            cur=node->next;
        }
        cur=pHead;
        while(cur)
        {
            RandomListNode* node=cur->next;
            if(cur->random)
                node->random=cur->random->next;
            cur=node->next;
        }
        cur=pHead;
        RandomListNode* tmp=NULL;
        RandomListNode* head=pHead->next;
        while(cur->next)
        {
            tmp=cur->next;
            cur->next=tmp->next;
            cur=tmp;
        }
         return head;
    }
};