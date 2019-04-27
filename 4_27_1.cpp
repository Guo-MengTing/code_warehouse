//数组中出现次数超过一半的数字
//1.
#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int size = s.size()/2;
		map<char, int> countmap;
		for (const auto&e : s)
		{
			auto it = countmap.find(e);
			if (it != countmap.end())
				(it->second)++;
			else
				countmap.insert(make_pair(e, 1));
		}
		map<char, int>::iterator it = countmap.begin();
		for (it; it != countmap.end(); ++it)
		{
			if (it->second > size)
			{
				return it->first;
			}
		}
		return 0;
	}
}

//2.
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size();
		map<int, int> countmap;
		int count;
		for (int i = 0; i<size; ++i)
		{
			count = ++countmap[numbers[i]];
			if (count>size / 2)
				return numbers[i];
		}
		return 0;
	}
};