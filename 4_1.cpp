1.https://leetcode-cn.com/problems/remove-linked-list-elements/description/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* removeElements(struct ListNode* head, int val) {
	struct ListNode* cur = head->next;
	struct ListNode* prev = head;
	struct ListNode* next = cur->next;
	while (next)
	{
		if (head->val == val)
		{
			head = cur;
			prev = head;
			cur = next;
			next = cur->next;
		}
		else
		{
			if (cur->val == val)
			{
				prev->next = next;
				prev = cur;
				cur = next;
				next = cur->next;
			}
			else
			{
				prev = cur;
				cur = next;
				next = cur->next;
			}
		}
	}
	return head;
}

2.https://leetcode-cn.com/problems/reverse-linked-list/description/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode* cur = head->next;
	struct ListNode* prev = head;
	struct ListNode* next = cur->next;
	prev->next = NULL;
	while (next != NULL)
	{
		cur->next = prev;
		prev = cur;
		cur = next;
		next = cur->next;
	}
	return cur;
}
3.https://leetcode-cn.com/problems/middle-of-the-linked-list/description/
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
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
4.https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&&tqId=11167&rp=2&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
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
5.https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode* head, *tail;
	if (l1 == NULL)
		return NULL;
	else if (l2 == NULL)
		return NULL;
	if (l1->val<l2->val)
	{
		head = l1;
		l1 = l1->next;
	}
	else
	{
		head = l2;
		l2 = l2->next;
	}
	tail = head;
	while (l1 != NULL&&l2 != NULL)
	{
		if (l1->val<l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1 != NULL)
		tail->next = l1;
	else if (l2 != NULL)
		tail->next = l2;

	return head;
}