#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)
class Solution {
    int m,n;
    vector<vector<vector<int>>>dp;

    int helper(vector<vector<int>>&coins,int i,int j,int skips){
        if(i>=m || j>=n)    return INT_MIN;
        if(i==m-1 && j==n-1){
            if(coins[i][j]<0 && skips>0)    return 0;
            else    return coins[i][j];
        }
        if(dp[i][j][skips]!=INT_MIN)    return dp[i][j][skips];
        int right=helper(coins,i,j+1,skips);
        int down=helper(coins,i+1,j,skips);
        int temp=max(right,down);
        int take=INT_MIN;
        if(temp!=INT_MIN)   take=temp+coins[i][j];
        int skip=INT_MIN;
        if(coins[i][j]<0 && skips>0){
            int rightSkip=helper(coins,i,j+1,skips-1);
            int downSkip=helper(coins,i+1,j,skips-1);
            skip=max(rightSkip,downSkip);
        }
        return dp[i][j][skips]=max(take,skip);
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();
        n=coins[0].size();
        dp.assign(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return helper(coins,0,0,2);
    }
};