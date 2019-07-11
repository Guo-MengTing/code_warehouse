//https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=3
class Solution {
public:
    int Add(int num1, int num2)
    {
        int tmp=0;
        while(num2)
        {
            tmp=num1^num2;
            num2=(num1&num2)<<1;
            num1=tmp;
        }
        return num1;
    }
};

//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int StrToInt(string str) {
        bool flag=true;
        int sum=0;
        for(int i=0;i<str.length();++i)
        {
            if(str[i]==' ')
            {}
            else if(str[i]=='+')
            {
                flag=true;
            }
            else if(str[i]=='-')
            {
                flag=false;
            }
            else if(str[i]<='9'&&str[i]>='0')
                sum=sum*10+str[i]-'0';
            else 
                return 0;
        }
        if(flag==true)
            return sum;
        else
            return -sum;
    }
};

//https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;
        ListNode* slow=pHead;
        ListNode* fast=pHead;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        ListNode* cur=pHead;
        while(cur!=slow)
        {
            cur=cur->next;
            slow=slow->next;
        }
        return cur;
    }
};