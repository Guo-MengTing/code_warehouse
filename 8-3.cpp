//https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    void reOrderArray(vector<int> &array) {
       /*vector<int>::iterator it=array.begin();
       vector<int> v;
       for(it;it!=array.end();)
       {
           if(*it%2!=0)
           {
               ++it;
           }
           else
           {
               v.push_back(*it);
               it=array.erase(it);
           }
       }
       vector<int>::iterator i=v.begin();
      for(i;i!=v.end();++i)
      {
          array.push_back(*i);
      }
      */
        for(int i=0;i<array.size();++i)
        {
            if(array[i]%2==0)
            {
                int tmp;
                for(int j=i;j<array.size();++j)
                {
                    if(array[j]%2==1)
                    {
                        tmp=array[j];
                        while(j>i)
                        {
                            array[j]=array[j-1];
                            --j;
                        }
                        array[j]=tmp;
                        ++i;
                    }
                }
                break;
            }
        }
    }
};

//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k<=0)
            return NULL;
        ListNode* slow=pListHead;
        ListNode* fast=pListHead;
        int m=k-1;
        while(m>0&&fast!=NULL)
        {
            fast=fast->next;
            m--;
        }
        if(fast==NULL||m>0)
        return NULL;
        if(fast->next==NULL)
            return pListHead;
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};

//https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead){
        if(pHead==NULL||pHead->next==NULL)
            return pHead;
        stack<ListNode*> s;
        ListNode* p=pHead;
        while(p->next)
        {
            s.push(p);
            p=p->next;
        }
        ListNode* head=p;
        while(!s.empty())
        {
           p->next=s.top();
           s.pop();
           p=p->next;
        }
        p->next=NULL;
        return head;
    }
};

//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* head=new ListNode(0);
        head->next=NULL;
        ListNode* cur=head;
        while(pHead1!=NULL&&pHead2!=NULL)
        {
            if(pHead1->val>=pHead2->val)
            {
                cur->next=pHead2;
                cur=cur->next;
                pHead2=pHead2->next;
            }
            else
            {
                cur->next=pHead1;
                cur=cur->next;
                pHead1=pHead1->next;
            }
        }
        if(pHead1)
            cur->next=pHead1;
        if(pHead2)
            cur->next=pHead2;
        return head->next;
    }
};