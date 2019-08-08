//https://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty()||dict.empty())
            return false;
        vector<bool> f(s.size()+1,false);
        f[0]=true;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(f[j]&&dict.find(s.substr(j,i-j))!=dict.end())
                {
                    f[i]=true;
                    break;
                }
            }
        }
        return f[s.size()];
    }
};

//https://www.nowcoder.com/practice/2b7995aa4f7949d99674d975489cb7da?tpId=46&tqId=29060&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-rankin
方法一：动态规划+考虑边界
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        vector<vector<int>> minT(triangle);
        int len=triangle.size();
        for(int i=1;i<len;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if(j==0)
                {
                    minT[i][j]=minT[i-1][j];
                }
                else if(j==i)
                {
                    minT[i][j]=minT[i-1][j-1];
                }
                else
                    minT[i][j]=min(minT[i-1][j],minT[i-1][j-1]);
                minT[i][j]=minT[i][j]+triangle[i][j];
            }
        }
        int ret=minT[len-1][0];
        for(int i=1;i<len;++i)
        {
            ret=min(minT[len-1][i],ret);
        }
        return ret;
    }
};

方法二：动态规划逆向思维+不考虑边界
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
            return 0;
        vector<vector<int>> minT(triangle);
        int len=triangle.size();
        for(int i=len-2;i>=0;--i)
        {
            for(int j=0;j<=i;++j)
            {
                minT[i][j]=min(minT[i+1][j],minT[i+1][j+1])+triangle[i][j];
            }
        }
        return minT[0][0];
    }
};

//https://www.nowcoder.com/practice/166eaff8439d4cd898e3ba933fbc6358?tpId=46&tqId=29117&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
转移方程：nPath[i][j]=nPath[i-1][j]+nPath[i][j-1]
注意第一行和第一列为1
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1||n<1)
            return 0;
        vector<vector<int>> nPath(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
        {
            nPath[i][0]=1;
        }
        for(int i=0;i<n;++i)
        {
            nPath[0][i]=1;
        }
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                nPath[i][j]=nPath[i-1][j]+nPath[i][j-1];
            }
        }
        return nPath[m-1][n-1];
    }
};

//https://www.nowcoder.com/practice/3cdf08dd4e974260921b712f0a5c8752?tpId=46&tqId=29116&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> up(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
        {
            if(obstacleGrid[i][0]==1)
            {
                break;
            }
            else
            {
                up[i][0]=1;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(obstacleGrid[0][i]==1)
                break;
            else
                up[0][i]=1;
        }
        for(int i=1;i<m;++i)
        {
            for(int j=1;j<n;++j)
            {
                if(obstacleGrid[i][j]==1)
                    up[i][j]=0;
                else
                up[i][j]=up[i-1][j]+up[i][j-1];
            }
        }
        return up[m-1][n-1];
    }
};