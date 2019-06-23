//https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum=array[0];
        int max=array[0];
        for(int i=1;i<array.size();++i)
        {
            if(sum>=0)
                sum+=array[i];
            else
                sum=array[i];
            if(sum>max)
                max=sum;
        }
        return max; 
    }
};

//https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
方法一：
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size()<k)
            return res;
        int i,j;
        for(int i=0;i<input.size();++i)
        {
            int min=i;
            for(int j=i+1;j<input.size();++j)
            {
                if(input[min]>input[j])
                {
                    min=j;
                }
            }
            int tmp=input[i];
            input[i]=input[min];
            input[min]=tmp;
        }
        for(int i=0;i<k;++i)
        {
            res.push_back(input[i]);
        }
        return res;
    }
};
方法二：
vector<int> res;
         if(input.size()<k)
            return res;
          for(int i=1;i<input.size();++i)
          {
              for(int j=i-1;j>=0;--j)
              {
                  if(input[i]<input[j])
                  {
                      int tmp=input[i];
                      input[i]=input[j];
                      input[j]=tmp;
                      i=j;
                  }
              }
          }
        for(int i=0;i<k;++i)
        {
            res.push_back(input[i]);
        }
        return res;

//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int> mp;
        for(int i=0;i<numbers.size();++i)
        {
            mp[numbers[i]]++;
        }
        map<int,int>::iterator it=mp.begin();
        int size=numbers.size()/2;
        for(it;it!=mp.end();++it)
        {
            if(it->second>size)
            {
                return it->first;
            }
        }
        return 0;
        
    }
};