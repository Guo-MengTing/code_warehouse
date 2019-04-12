//1.https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&&tqId=11004&rp=2&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* cur = pHead;
		ListNode* small = new ListNode(-1);
		ListNode* big = new ListNode(-1);
		ListNode* s = small;
		ListNode* b = big;
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		while (cur)
		{
			if (cur->val<x)
			{
				s->next = new ListNode(cur->val);
				s = s->next;
				cur = cur->next;
			}
			else{
				b->next = new ListNode(cur->val);
				b = b->next;
				cur = cur->next;
			}
		}
		s->next = big->next;
		return small->next;
		return 0;
	}
};

//2.https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&&tqId=11209&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* cur = pHead;
		ListNode* small = new ListNode(-1);
		ListNode* big = new ListNode(-1);
		ListNode* s = small;
		ListNode* b = big;
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		while (cur)
		{
			if (cur->val<x)
			{
				s->next = new ListNode(cur->val);
				s = s->next;
				cur = cur->next;
			}
			else{
				b->next = new ListNode(cur->val);
				b = b->next;
				cur = cur->next;
			}
		}
		s->next = big->next;
		return small->next;
		return 0;
	}
};

//3.https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || k == 0)
			return NULL;
		ListNode* p1 = pListHead;
		ListNode* p2 = pListHead;
		int count = 0;
		for (int i = 0; i<k - 1; ++i)
		{
			if (p1->next == NULL)
				return NULL;
			else
			{
				p1 = p1->next;
			}
		}
		while (p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p2;
	}
};

//4.https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow = head;
	struct ListNode* fast = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}