#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2 log n)
// Space Complexity: O(n^2)
class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>dist(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx<0 || nx>=n || ny<0 || ny>=n || dist[nx][ny]!=-1)  continue;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
        priority_queue<vector<int>>pq;
        pq.push({dist[0][0],0,0});
        vector<vector<int>>vis(n,vector<int>(n,0));
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int safe=curr[0];
            int x=curr[1];
            int y=curr[2];
            if(vis[x][y])   continue;
            vis[x][y]=1;
            if(x==n-1 && y==n-1)    return safe;
            for(int k=0;k<4;k++){
                int nx=x+dir[k][0];
                int ny=y+dir[k][1];
                if(nx<0 || nx>=n || ny<0 || ny>=n)  continue;
                if(vis[nx][ny]) continue;
                pq.push({min(safe,dist[nx][ny]),nx,ny});
            }
        }
        return 0;
    }
};