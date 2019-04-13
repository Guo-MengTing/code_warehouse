//1.https://leetcode-cn.com/problems/linked-list-cycle/description/
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast->next != NULL&&fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				return true;
				break;
			}
		}
		return NULL;
	}

};
//2.https://leetcode-cn.com/problems/linked-list-cycle-ii/description/
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL)
			return NULL;
		ListNode* fast = head;
		ListNode* slow = head;
		bool hascycle = false;
		while (fast->next != NULL&&fast->next->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast)
			{
				hascycle = true;
				break;
			}
		}
		if (hascycle)
		{
			ListNode* p = head;
			while (p != slow)
			{
				p = p->next;
				slow = slow->next;
			}
			return p;
		}
		else
			return NULL;

	}
};
//3.https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int len1 = 0;
	int len2 = 0;
	struct ListNode* hh1 = headA;
	struct ListNode* hh2 = headB;
	while (hh1 != NULL)
	{
		++len1;
		hh1 = hh1->next;
	}
	while (hh2 != NULL)
	{
		++len2;
		hh2 = hh2->next;
	}
	struct ListNode* h1 = headA;
	struct ListNode* h2 = headB;
	if (len1>len2)
	{
		int gab = len1 - len2;
		while (gab != 0)
		{
			h1 = h1->next;
			--gab;
		}
	}
	else if (len1<len2)
	{
		int gab = len2 - len1;
		while (gab != 0)
		{
			h2 = h2->next;
			--gab;
		}
	}

	while (h1 != NULL&&h2 != NULL)
	{
		if (h1 == h2)
		{
			return h1;
		}
		h1 = h1->next;
		h2 = h2->next;
	}
	return NULL;
}