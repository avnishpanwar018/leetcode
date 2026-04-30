#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n * k)
// Space Complexity: O(m * n * k)
class Solution {
public:
    int m,n;
    vector<vector<vector<int>>>dp;

    int helper(int r,int c, vector<vector<int>>&grid,int k){
        if(r>=m || c>=n || k<0) return -1;
        if(dp[r][c][k]!=INT_MIN)    return dp[r][c][k];
        int val=grid[r][c];
        if(val>0 && k==0)   return dp[r][c][k]=-1;
        if(r==m-1 && c==n-1)    return dp[r][c][k]=val;
        int nextK=k;
        if(val>0)   nextK--;
        int right=helper(r,c+1,grid,nextK);
        int down=helper(r+1,c,grid,nextK);
        if(right==-1 && down==-1)   return dp[r][c][k]=-1;
        return dp[r][c][k]=val+max(right,down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(k+1,INT_MIN)));
        return helper(0,0,grid,k);
    }
};