//https://www.nowcoder.com/questionTerminal/e02fdb54d7524710a7d664d082bb7811
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int len=data.size();
        if(len==2)
            return;
        int sum=data[0];
        for(int i=1;i<len;++i)
        {
            sum=sum^data[i];
        }
        if(sum==0)
            return;
        int index=0;
        while((sum&1)==0)
        {
            sum=sum>>1;
            ++index;
        }
        *num1=0;
        *num2=0;
        for(int i=0;i<len;++i)
        {
            if(isThis(data[i],index))
                *num1^=data[i];
            else
                *num2^=data[i];
        }
    }
    bool isThis(int x,int index)
    {
        x=x>>index;
        return x&1;
    }
};

//https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char,int> mp;
        for(int i=0;i<str.size();++i)
        {
            mp[str[i]]++;
        }
        for(int i=0;i<str.size();++i)
        {
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};

//https://www.nowcoder.com/questionTerminal/c451a3fd84b64cb19485dad758a55ebe
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int low=1;
        int high=2;
        while(low<high)
        {
            int count=(low+high)*(high-low+1)/2;
            if(count==sum)
            {
                vector<int> v;
                for(int i=low;i<=high;++i)
                {
                    v.push_back(i);
                }
                res.push_back(v);
                ++low;
            }
            else if(count<sum)
                ++high;
            else
                ++low;
        }
        return res;
    }
};
