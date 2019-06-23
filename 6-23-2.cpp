//https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    vector<string> res;
    vector<string> Permutation(string str) {
        if(str.size()==0)
            return res;
        int size=str.size();
        Get(str,0,size);
        sort(res.begin(),res.end());
        auto it= unique(res.begin(),res.end());
        res.erase(it,res.end());
        return res;
    }
    void Get(string& str,int i,int len)
    {
        if(str[i]=='\0')
            res.push_back(str);
        else
        {
            for(int start=i;start<len;++start)
            {
              swap(str[i],str[start]);
              Get(str,i+1,len);
              swap(str[i],str[start]);
            }
        }
    }
};