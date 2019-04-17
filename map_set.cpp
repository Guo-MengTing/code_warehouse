#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;

//int main()
//{
//	set<int> s;
//	s.insert(3);
//	s.insert(5);
//	s.insert(3);
//	s.insert(2);
//	s.insert(1);
//	s.insert(7);
//	set<int>::iterator it = s.begin();
//	for (it; it != s.end(); ++it)
//	{
//		cout << *it<<' ';
//	}
//	cout << endl;
//    
//	it = s.find(8);
//	s.erase(it);
//	if (it != s.end())
//		cout << "找到了" << endl;
//	else
//		cout << "没找到" << endl;
//
//	s.erase(8);
//	it = s.find(3);
//	if (it != s.end())
//		cout << "找到了" << endl;
//	else
//		cout << "没找到" << endl;
//}

//int main()
//{
//	multiset<int> ms;
//	ms.insert(3);
//	ms.insert(1);
//	ms.insert(6);
//	ms.insert(9);
//	ms.insert(3);
//	ms.insert(7);
//	for (auto it : ms)
//	{
//		cout << it << ' ';
//	}
//	cout << endl;
//
//	multiset<int>::iterator is = ms.begin();
//	is =ms.find(3);
//	if (is != ms.end())
//		cout << "找到了" << endl;
//}

//template<class K,class V>
//inline std::pair<K, V> make_pair(const K& k, const V& v)
//{
//	return std::pair<K,V>(k,v);
//}
//
int main()
{
	multimap<string, string> mp;
	mp.insert(pair<string, string>("苹果","apple"));
	mp.insert(pair<string, string>("香蕉", "banana"));
	mp.insert(pair<string, string>("梨","pear"));
	mp.insert(pair<string, string>("梨", "pear"));
	mp.insert(make_pair("桃子", "peach"));
	
	map<string, string>::iterator it = mp.begin();
	while (it != mp.end())
	{
		cout << it->first << ":" <<it->second<<endl;
		++it;
	}
}

//int main()
//{
//	string s[] = { "苹果", "梨", "桃子", "苹果", "西瓜", "桃子", "苹果" };
//	map<string, int> mp;
//	for (const auto& str : s)
//	{
//		auto it = mp.find(str);
//		if (it != mp.end())
//			it->second++;
//		else
//			mp.insert(make_pair(str, 1));
//	}
//	map<string, int>::iterator it = mp.begin();
//	while (it != mp.end())
//	{
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//}