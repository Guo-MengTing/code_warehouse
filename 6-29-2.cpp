//https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        map<int,int> mp;
        int i=0;
        int j=0;
        for(i;i<data.size();++i)
        {
            mp[data[i]]++;
        }
        map<int,int>::iterator it=mp.begin();
        for(it;it!=mp.end();++it)
        {
            if(it->first==k)
                break;
        }
        return it->second;
    }
};