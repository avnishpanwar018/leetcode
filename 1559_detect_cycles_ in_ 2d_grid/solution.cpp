#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> dirs={{0,1},{1,0},{0,-1},{-1,0}};

    bool dfs(int pr,int pc,int r,int c,char ch,vector<vector<char>>&grid){
        visited[r][c]=true;
        for(auto &dir:dirs){
            int x=r+dir[0];
            int y=c+dir[1];
            if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size())   continue;
            if(ch!=grid[x][y])  continue;
            if(!visited[x][y]){
                if(dfs(r,c,x,y,ch,grid))    return true;
            }
            else if(!(x==pr && y==pc))  return true;
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        visited.resize(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && dfs(-1,-1,i,j,grid[i][j],grid))    return true;
            }
        }
        return false;
    }
};