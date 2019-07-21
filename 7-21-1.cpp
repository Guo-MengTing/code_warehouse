//https://www.nowcoder.com/questionTerminal/12d959b108cb42b1ab72cef4d36af5ec
方法一：
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len=str.length();
        string s="";
        for(int i=0;i<n;++i)
        {
            s+=str[i];
        }
        str+=s;
        return str.substr(n,len);
    }
};
方法二：
class Solution {
public:
    string LeftRotateString(string str, int n) {
       reverse(str.begin(),str.end());
       reverse(str.begin(),str.begin()+str.length()-n);
       reverse(str.begin()+str.length()-n,str.end());
       return str;
    }
};

//https://www.nowcoder.com/questionTerminal/3194a4f4cf814f63919d0790578d51f3
class Solution {
public:
    void Reverse(string& str,int s,int e)
    {
        while(s<e)
        {
            swap(str[s],str[e]);
            ++s;
            --e;
        }
    }
    string ReverseSentence(string str) {
        Reverse(str,0,str.length()-1);
        int start=0;
        int end=0;
        int i=0;
        while(i<str.size())
        {
            while(str[i]==' '&&i<str.size())
                ++i;
            start=end=i;
            while(str[i]!=' '&&i<str.size())
            {
                ++i;
                ++end;
            }
            Reverse(str,start,end-1);
        }
        return str;
    }
};