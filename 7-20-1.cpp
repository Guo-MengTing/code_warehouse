//https://www.nowcoder.com/questionTerminal/390da4f7a00f44bea7c2f3d19491311b
方法一：比较法
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int i=0;
        int j=array.size()-1;
        int tmp=INT_MAX;
        while(i<j)
        {
            int count=array[i]+array[j];
            int mul=array[i]*array[j];
            if(count==sum)
            {
                if(mul<tmp)
                {
                    res.clear();
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    tmp=mul;
                }
                ++i;
                --j;
            }
            else if(count<sum)
                ++i;
            else
                --j;
        }
        return res;
    }
};
方法二：简便方法
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int i=0;
        int j=array.size()-1;
        vector<int> res;
        while(i<j)
        {
            int tmp=array[i]+array[j];
            if(tmp==sum)
            {
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
            else if(tmp<sum)
                ++i;
            else
                --j;
        }
        return res;
    }
};


