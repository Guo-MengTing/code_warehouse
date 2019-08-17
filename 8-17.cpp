//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
法一：先反转链表再插入值
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        if(head==NULL)
            return v;
        if(head->next==NULL)
        {
            v.push_back(head->val);
            return v;
        }
        ListNode* cur=head;
        ListNode* prev=cur->next;
        cur->next=NULL;
        while(cur!=NULL&&prev!=NULL)
        {
            ListNode* next=prev->next;
            prev->next=cur;
            cur=prev;
            prev=next;
        }
        while(cur!=NULL)
        {
            v.push_back(cur->val);
            cur=cur->next;
        }
        return v;
    }
};

法二:利用栈
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> v;
        if(head==NULL)
            return v;
        if(head->next==NULL)
        {
            v.push_back(head->val);
            return v;
        }
        stack<int> st;
        ListNode* cur=head;
        while(cur!=NULL)
        {
            st.push(cur->val);
            cur=cur->next;
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
};

//https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent>0)
        {
            if(exponent==1)
                return base;
            else if(exponent%2==0)
                return Power(base,exponent/2)*Power(base,exponent/2);
            else
                return Power(base,exponent/2+1)*Power(base,exponent/2);
        }
        else if(exponent==0)
            return 1;
        else
        {
            return 1/Power(base,0-exponent);
        }
    }
};

//https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int num=0;
        for(int i=0;i<length;++i)
        {
            if(str[i]==' ')
                ++num;
        }
        for(int j=length-1;j>=0;--j)
        {
            if(str[j]!=' ')
            {
                str[j+num*2]=str[j];
            }
            else
            {
                --num;
                str[j+num*2]='%';
                str[j+num*2+1]='2';
                str[j+num*2+2]='0';
            }
        }
	}
};

//https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.size()==0||vin.size()==0||(pre.size()!=vin.size()))
            return NULL;
        int value=pre[0];
        TreeNode* cur=new TreeNode(value);
        int i,j;
        std::vector<int> pre_left,vin_left,pre_right,vin_right;
        for(i=0;i<vin.size();++i)
        {
            if(vin[i]==value)
                break;
        }
        for(j=0;j<vin.size();++j)
        {
            if(j<i)
            {
                vin_left.push_back(vin[j]);
                pre_left.push_back(pre[j+1]);
            }
            if(j>i)
            {
                vin_right.push_back(vin[j]);
                pre_right.push_back(pre[j]);
            }
        }
        cur->left=reConstructBinaryTree(pre_left,vin_left);
        cur->right=reConstructBinaryTree(pre_right,vin_right);
        return cur;
    }
};