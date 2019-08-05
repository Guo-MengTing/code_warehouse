//归并排序
#include<iostream>
#include<vector>
using namespace std;
void mergesort(vector<int>& v, int l, int r, int mid)
{
	vector<int> tmp(r - l + 1);
	for (int i = l; i <= r; ++i)
	{
		tmp[i - l] = v[i];
	}
	int st = l;
	int right = mid + 1;
	for (int i = l; i <= r; ++i)
	{
		if (st > mid)
		{
			v[i] = tmp[right - l];
			++right;
		}
		else if (right > r)
		{
			v[i] = tmp[st - l];
			++st;
		}
		else if (tmp[st - l] >= tmp[right - l])
		{
			v[i] = tmp[right - l];
			++right;
		}
		else
		{
			v[i] = tmp[st - l];
			++st;
		}
	}
}
void merge_sort(vector<int>& v, int l, int r)
{
	if (l >= r)
		return;
	int mid = (l + r) / 2;
	merge_sort(v,l, mid);
	merge_sort(v, mid + 1, r);
	mergesort(v, l, r, mid);
}
int main()
{
	vector<int> v{ 1, 3, 2, 5, 7, 0, 4 };
	int len = v.size();
	merge_sort(v, 0, len-1);
	for (int i = 0; i < len; ++i)
	{
		cout << v[i];
	}
	cout << endl;
	return 0;
}

//链表排序（使用归并排序）
//https://www.nowcoder.com/questionTerminal/d75c232a0405427098a8d1627930bea6
class Solution {
public:
	ListNode *sortList(ListNode *head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode *mid = GetMiddle(head);
		ListNode *headnext = mid->next;
		mid->next = NULL;
		return mergesort(sortList(head), sortList(headnext));

	}
	ListNode *GetMiddle(ListNode *head)
	{
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL&&fast->next != NULL&&fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
	ListNode *mergesort(ListNode* h1, ListNode* h2)
	{
		ListNode* phead = new ListNode(0);
		ListNode* cur = phead;
		ListNode* cur1 = h1;
		ListNode* cur2 = h2;
		while (cur1 != NULL&&cur2 != NULL)
		{
			if (cur1->val >= cur2->val)
			{
				cur->next = cur2;
				cur = cur->next;
				cur2 = cur2->next;
			}
			else
			{
				cur->next = cur1;
				cur = cur->next;
				cur1 = cur1->next;
			}
		}
		if (cur1 == NULL)
			cur->next = cur2;
		else
			cur->next = cur1;
		return phead->next;
	}
};