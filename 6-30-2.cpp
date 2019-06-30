//https://www.nowcoder.com/practice/d281619e4b3e4a60a2cc66ea32855bfa?tpId=49&&tqId=29370&rp=1&ru=/activity/oj&qru=/ta/2016test/question-ranking
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        struct ListNode* cur=A;
        int a[900];
        int n=0;
        while(cur)
        {
            a[n++]=cur->val;
            cur=cur->next;
        }
        int left=0;
        int right=n-1;
        while(left<right)
        {
            if(a[left]!=a[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};

//https://leetcode-cn.com/problems/intersection-of-two-linked-lists/description/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA=0;
    int lenB=0;
    struct ListNode *curA=headA,*curB=headB;
    while(curA)
    {
        ++lenA;
        curA=curA->next;
    }
    while(curB)
    {
        ++lenB;
        curB=curB->next;
    }
    int gap=abs(lenA-lenB);
    struct ListNode* longlist=headA,*shortlist=headB;
    if(lenA<lenB)
    {
        longlist=headB;
        shortlist=headA;
    }
    while(gap--)
    {
        longlist=longlist->next;
    }
    while(shortlist && longlist)
    {
        if(shortlist->val == longlist->val)
            return longlist;
        else
        {
            shortlist=shortlist->next;
            longlist=longlist->next;
        }
        
    }
    return NULL;
}
