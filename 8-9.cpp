//https://www.nowcoder.com/practice/23462ed010024fcabb7dbd3df57c715e?tpId=46&tqId=29115&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>> minP(grid);
        for(int i=1;i<row;++i)
        {
            minP[i][0]=minP[i-1][0]+grid[i][0];
        }
        for(int i=1;i<col;++i)
        {
            minP[0][i]=minP[0][i-1]+grid[0][i];
        }
        for(int i=1;i<row;++i)
        {
            for(int j=1;j<col;++j)
            {
                minP[i][j]=min(minP[i-1][j],minP[i][j-1])+grid[i][j];
            }
        }
        return minP[row-1][col-1];
    }
};

//https://www.nowcoder.com/practice/1025ffc2939547e39e8a38a955de1dd3?tpId=46&tqId=29048&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
class Solution {
public:
    int minCut(string s) {
       if(s.empty())
           return 0;
        vector<int> minC(s.size()+1);
        minC[0]=-1;
        for(int i=1;i<s.size()+1;++i)
        {
            minC[i]=i-1;
        }
        for(int i=1;i<s.size()+1;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(isHuiWen(s,j,i-1))
                    minC[i]=min(minC[i],minC[j]+1);
            }
        }
        return minC[s.size()];
    }
    bool isHuiWen(string& s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            else
            {
                ++i;
                --j;
            }
        }
        return true;
    }
};

//https://www.nowcoder.com/practice/81d7738f954242e5ade5e65ec40e5027?tpId=46&tqId=29106&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
/*
状态：F[i,j]表示从word1前i个字符与word2前i个字符的编辑距离
转移方程：
      F[i,j]=min(F[i-1][j],F[i][j-1])+1;   //删除或者增加
	  如果word1的第i个字符和第word2的第j个字符相同，
	  F[i][j]=min(F[i-1][j-1],F[i][j]);
	  否则
	  F[i][j]=min(F[i-1][j-1]+1,F[i][j]);
	  
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.empty())
            return word2.size();
        if(word2.empty())
            return word1.size();
        int len1=word1.size();
        int len2=word2.size();
        vector<vector<int>> minD(len1+1,vector<int>(len2+1,0));
        for(int i=0;i<len2+1;++i)
        {
            minD[0][i]=i;
        }
        for(int i=0;i<len1+1;++i)
        {
            minD[i][0]=i;
        }
        for(int i=1;i<len1+1;++i)
        {
            for(int j=1;j<len2+1;++j)
            {
                minD[i][j]=min(minD[i-1][j],minD[i][j-1])+1;
                if(word1[i-1]==word2[j-1])
                    minD[i][j]=min(minD[i-1][j-1],minD[i][j]);
                else
                    minD[i][j]=min(minD[i-1][j-1]+1,minD[i][j]);
            }
        }
        return minD[len1][len2];
    }
};