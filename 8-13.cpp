//https://leetcode-cn.com/problems/surrounded-regions/submissions/
class Solution {
public:
    void _solve(int x,int y,vector<vector<char>>& board)
    {
        board[x][y]='Z';
        static int go[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<4;++i)
        {
            int nx=x+go[i][0];
            int ny=y+go[i][1];
            if(nx<0||nx>=board.size()||ny<0||ny>=board[0].size())
                continue;
            if(board[nx][ny]=='O')
               _solve(nx,ny,board);
        }
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<col;++i)
        {
            if(board[0][i]=='O')
                _solve(0,i,board);
            if(board[row-1][i]=='O')
                _solve(row-1,i,board);
        }
        for(int i=0;i<row;++i)
        {
            if(board[i][0]=='O')
                _solve(i,0,board);
            if(board[i][col-1]=='O')
                _solve(i,col-1,board);
        }
        for(int i=0;i<row;++i)
        {
            for(int j=0;j<col;++j)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='Z')
                    board[i][j]='O';
            }
        }
    }
};

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
void Get(int i, int len, string& str, vector<string>& res)
{
	if (str[i] == '\0')
		res.push_back(str);
	else
	{
		for (int st = i; st < len; ++st)
		{
			swap(str[i], str[st]);
			Get(i + 1, len, str, res);
			swap(str[i], str[st]);
		}
	}
}
int main()
{
	string str;
	while (getline(cin, str))
	{
		vector<string> res;
		int len = str.size();
		Get(0, len, str, res);
		sort(res.begin(), res.end());
		auto it = unique(res.begin(), res.end());   //unique会将字符串数组中相同的元素放在数组最后
		res.erase(it, res.end());
		for (int i = 0; i < res.size(); ++i)
		{
			cout << res[i] << endl;
		}
	}
}