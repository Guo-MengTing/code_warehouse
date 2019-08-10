//盒子放牌问题
#include<iostream>
#include<vector>
using namespace std;
void DFS(int index, int n, vector<int>& box, vector<int>& mark)
{
	if (index == n + 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (mark[i] == 0)
		{
			box[index] = i;
			mark[i] = 1;
			DFS(index + 1, n, box, mark);
			mark[i] = 0;
		}
	}
}
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> box(n+1,0);
		vector<int> mark(n + 1, 0);
		DFS(1, n, box, mark);
	}
	return 0;
}

//https://leetcode-cn.com/problems/employee-importance/submissions/
class Solution {
public:
    void DFS(int &sum,unordered_map<int,Employee*>& mp,int id)
    {
        sum+=mp[id]->importance;
        for(auto &e:mp[id]->subordinates)
        {
            DFS(sum,mp,e);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
            return 0;
        unordered_map<int,Employee*> mp;
        for(auto &e:employees)
            mp[e->id]=e;
        int sum=0;
        DFS(sum,mp,id);
        return sum;
    }
};

class Solution {
public:
    int DFS(unordered_map<int,Employee*>& mp,int id)
    {
        int sum=mp[id]->importance;
        for(auto &e:mp[id]->subordinates)
        {
            sum+=DFS(mp,e);
        }
        return sum;
    }
    int getImportance(vector<Employee*> employees, int id) {
        if(employees.empty())
            return 0;
        unordered_map<int,Employee*> mp;
        for(auto &e:employees)
            mp[e->id]=e;
        return DFS(mp,id);
    }
};

//https://leetcode-cn.com/problems/flood-fill/submissions/
class Solution {
public:
    void dfs(vector<vector<int>>& image,vector<vector<int>>& mark,int sr,int sc,int row,int col,int oldColor,int newColor)
    {
        static int go[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        image[sr][sc]=newColor;
        mark[sr][sc]=1;
        for(int i=0;i<4;++i)
        {
            int nsr=sr+go[i][0];
            int nsc=sc+go[i][1];
            if(nsr<0||nsr>=row||nsc<0||nsc>=col)
                continue;
            if(image[nsr][nsc]==oldColor&&mark[nsr][nsc]==0)
                dfs(image,mark,nsr,nsc,row,col,oldColor,newColor);
                
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor)     {
        if(image.empty())
            return image;
        int row=image.size();
        int col=image[0].size();
        vector<vector<int>> mark(row,vector<int>(col,0));
        int oldColor=image[sr][sc];
        dfs(image,mark,sr,sc,row,col,oldColor,newColor);
        return image;
    }
};