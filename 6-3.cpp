//二进制插入
class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        int move=m<<j;
        int ret=n+move;
        return ret;
    }
};

//查找组成一个偶数最接近的两个素数
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
bool isSu(int n)
{
	if (n == 1 || n == 2)
		return true;
	for (int i = 2; i < n; ++i)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		stack<int> st;
		int i, j;
		for (i = 0; i <= n/2; ++i)
		{
			j = n - i;
			if (isSu(i) && isSu(j))
			{
				st.push(j);
				st.push(i);
			}
			
		}
		cout << st.top() << endl;
		st.pop();
		cout << st.top() << endl;
	}
}