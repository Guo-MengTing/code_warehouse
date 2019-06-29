//https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL)
            return NULL;
        int len1=0;
        int len2=0;
        int gap=0;
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        while(p1)
        {
            ++len1;
            p1=p1->next;
        }
        while(p2)
        {
            ++len2;
            p2=p2->next;
        }
        if(len1>len2)
        {
            gap=len1-len2;
            while(gap>0)
            {
                pHead1=pHead1->next;
                --gap;
            }
        }
        else{
            gap=len2-len1;
            while(gap>0)
            {
                pHead2=pHead2->next;
                --gap;
            }
        }
        while(pHead1&&pHead2)
        {
           if(pHead1==pHead2)
               return pHead1;
           else
           {
               pHead1=pHead1->next;
               pHead2=pHead2->next;
           }
        }
        return NULL;
    }
};