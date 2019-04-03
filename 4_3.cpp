//跳台阶
class Solution {
public:
	int jumpFloor(int number) {
		if (number == 0 || number == 1)
			return 1;
		int f0 = 0;
		int f1 = 1;
		int f2;
		for (int i = 0; i<number; ++i)
		{
			f2 = f0 + f1;
			f0 = f1;
			f1 = f2;
		}
		return f2;
	}
};

//变态跳台阶
class Solution {
public:
	int jumpFloorII(int number) {
		return 1 << (number - 1);
	}
};

//矩形覆盖
class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		int f1 = 0;
		int f2 = 1;
		int f3;
		for (int i = 0; i<number; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};

//斐波那契数列
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		int f1 = 0;
		int f2 = 1;
		int f3;
		for (int i = 1; i<n; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};

//从尾到头打印链表
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		std::vector<int> v;
		std::stack<int> s;
		while (head)
		{
			s.push(head->val);
			head = head->next;
		}
		while (!s.empty())
		{
			v.push_back(s.top());
			s.pop();
		}
		return v;
	}
};