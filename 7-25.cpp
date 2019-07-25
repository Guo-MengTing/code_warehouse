//https://leetcode-cn.com/problems/two-sum/submissions/
方法一：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();++i)
        {
            int tmp=target-nums[i];
            if(um.count(tmp))
            {
                res.push_back(um[tmp]);
                res.push_back(i);
                break;
            }
            um[nums[i]]=i;
        }
        return res;
    }
};
方法二：暴力解法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i=0;
        int j=0;
        for(;i<nums.size();++i)
        {
            for(j=i+1;j<nums.size();++j)
            {
                if(nums[i]+nums[j]==target)
                {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};

//https://leetcode-cn.com/problems/add-two-numbers/comments/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode vHead(0), *p = &vHead;
        int flag = 0;
        while (l1 || l2 || flag) {
            int tmp = 0;
            if (l1 != nullptr) tmp += l1->val;
            if (l2 != nullptr) tmp += l2->val;
            tmp += flag;
            
            flag = tmp / 10;
            tmp %= 10;
            
            ListNode *next = l1 ? l1 : l2;
            if (next == nullptr) next = new ListNode(tmp);
            next->val = tmp;
            
            p->next = next;
            p = p->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return vHead.next;
    }
};