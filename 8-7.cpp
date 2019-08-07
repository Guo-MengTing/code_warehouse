//https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
方法一：动态规划(开辅助空间)
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> f(n+1);
        f[0]=0;
        f[1]=1;
        for(int i=2;i<=n;++i)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[n];
    }
};
方法二：动态规划
class Solution {
public:
    int Fibonacci(int n) {
        if(n==1||n==2)
            return 1;
        int f=0;
        int f1=1;
        int f2=1;
        for(int i=3;i<=n;++i)
        {
            f=f1+f2;
            f1=f2;
            f2=f;
        }
        return f;
    }
};
方法三：递归
class Solution {
public:
    int Fibonacci(int n) {
        if(n<0)
            return 0;
        if(n==1||n==2)
            return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};

//https://www.nowcoder.com/practice/22243d016f6b47f2a6928b4313c85387?tpId=13&tqId=11162&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
方法一：
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> f(number+1);
        f[0]=0;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=number;++i)
        {
            f[i]=2*f[i-1];
        }
        return f[number];
    }
};
方法二：
class Solution {
public:
    int jumpFloorII(int number) {
        return 1<<(number-1);
    }
};

//https://www.nowcoder.com/questionTerminal/72a5a919508a4251859fb2cfb987a0e6
class Solution {
public:
    int rectCover(int number) {
        vector<int> f(number+1);
        f[0]=0;
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=number;++i)
        {
            f[i]=f[i-1]+f[i-2];
        }
        return f[number];
    }
};

//https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxSum=array[0];
        int sum=array[0];
        for(int i=1;i<array.size();++i)
        {
            sum=max(sum+array[i],array[i]);
            maxSum=max(sum,maxSum);
        }
        return maxSum;
    }
};