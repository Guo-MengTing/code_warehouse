//https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
写法一：
class Solution {
public:
    static bool cmp(int i,int j)
    {
        string A="";
        string B="";
        A+=to_string(i);
        A+=to_string(j);
        B+=to_string(j);
        B+=to_string(i);
        return A<B;
    /
    string PrintMinNumber(vector<int> numbers) {
        string s="";
        sort(numbers.begin(),numbers.end(),cmp);
        for(int i=0;i<numbers.size();++i)
        {
            s+=to_string(numbers[i]);
        }
        return s;
    }
};

写法二：利用lambda表达式
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string s="";
        sort(numbers.begin(),numbers.end(),
             [](int i,int j)->bool{return to_string(i)+to_string(j)<to_string(j)+to_string(i);
                            });
        for(int i=0;i<numbers.size();++i)
        {
            s+=to_string(numbers[i]);
        }
        return s;
    }
};