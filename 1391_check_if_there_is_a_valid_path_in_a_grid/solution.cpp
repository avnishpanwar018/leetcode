#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    vector<vector<bool>>visited;
    vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
    vector<bool>canRight={false,true,false,false,true,false,true};
    vector<bool>canLeft={false,true,false,true,false,true,false};
    vector<bool>canUp={false,false,true,false,false,true,true};
    vector<bool>canDown={false,false,true,true,true,false,false};

    bool canMove(int curr,int next,int dir){
        if(dir==0)  return canRight[curr] && canLeft[next];
        else if(dir==1) return canDown[curr] && canUp[next];
        else if(dir==2) return canLeft[curr] && canRight[next];
        else if(dir==3) return canUp[curr] && canDown[next];
        return false;
    }

    bool dfs(int r,int c,vector<vector<int>>&grid){
        if(r==grid.size()-1 && c==grid[0].size()-1) return true;
        visited[r][c]=true;
        for(int i=0;i<4;i++){
            int nr=r+dirs[i][0];
            int nc=c+dirs[i][1];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && !visited[nr][nc] && canMove(grid[r][c],grid[nr][nc],i)){
                if(dfs(nr,nc,grid)) return true;
            }
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        visited.resize(m,vector<bool>(n,false));
        return dfs(0,0,grid);
    }
};