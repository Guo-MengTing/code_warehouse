//https://www.nowcoder.com/questionTerminal/762836f4d43d43ca9deb273b3de8e1f4
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        sort(numbers.begin(),numbers.end());
        if(numbers.size()==0||numbers.size()<=4)
            return false;
        int count=0;
        int totalGap=0;
        for(int i=0;i<numbers.size();++i)
        {
            if(numbers[i]==0)
                ++count;
        }
        for(int j=0;j<numbers.size()-1;++j)
        {
            if(numbers[j+1]!=0&&numbers[j]!=0)
            {
                int gap=numbers[j+1]-numbers[j]-1;
                if(gap<0)
                    return false;
                else
                    totalGap+=gap;
            }
        }
        if(totalGap>count)
            return false;
        else
            return true;
}
};

//https://www.nowcoder.com/questionTerminal/f78a359491e64a50bce2d89cff857eb6
方法一：list容器+迭代器模拟环
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        list<int> ls;
        for(int i=0;i<n;++i)
        {
            ls.push_back(i);
        }
        list<int>::iterator cur=ls.begin();
        while(ls.size()>1)
        {
            for(int i=0;i<m-1;++i)
            {
                ++cur;
                if(cur==ls.end())
                    cur=ls.begin();
            }
            ++cur;
            list<int>::iterator next=cur;
            if(next==ls.end())
                next=ls.begin();
            --cur;
            ls.erase(cur);
            cur=next;
        }
        return *cur;
    }
};
方法二：用链表节点模拟环过程
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
        return res->val;
    }
};
