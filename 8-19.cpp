//https://leetcode-cn.com/problems/reverse-linked-list-ii/submissions/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL)
            return head;
        if(n==m)
            return head;
        ListNode* newhead=new ListNode(-1);
        newhead->next=head;
        ListNode* pre=newhead;
        for(int i=0;i<m-1;i++)
            pre=pre->next;
        ListNode* cur=pre->next;
        for(int i=m;i<n;++i)
        {
            ListNode* n=cur->next;
            cur->next=n->next;
            n->next=pre->next;
            pre->next=n;
        }
        return newhead->next;
    }
};

//https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/submissions/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=head;
        while(fast&&fast->next)
        {
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode* r=slow->next;
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(r);
        return root;
    }
};

//https://leetcode-cn.com/problems/copy-list-with-random-pointer/submissions/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node* cur=head;
        while(cur!=NULL)
        {
            Node* tmp=new Node(cur->val,cur->next,NULL);
            tmp->next=cur->next;
            cur->next=tmp;
            cur=tmp->next;
        }
        cur=head;
        Node* p=NULL;
        while(cur)
        {
            p=cur->next;
            if(cur->random)
                p->random=cur->random->next;
            cur=p->next;
        }
        cur=head;
        Node* newhead=head->next;
        p=NULL;
        while(cur&&cur->next)
        {
            p=cur->next;
            cur->next=p->next;
            cur=p;
        }
        return newhead;
    }
};

//https://leetcode-cn.com/problems/reorder-list/submissions/
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return ;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* right=slow->next;
        slow->next=NULL;
        ListNode* pre=NULL;
        while(right)
        {
            ListNode* next=right->next;
            right->next=pre;
            pre=right;
            right=next;
        }
        ListNode* n1=NULL;
        ListNode* n2=NULL;
        right=pre;
        ListNode* cur=head;
        while(cur&&right)
        {
            n1=cur->next;
            n2=right->next;
            cur->next=right;
            cur=n1;
            right->next=cur;
            right=n2;
        }
        
    }
};