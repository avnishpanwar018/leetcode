#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n ^ 3)
// Space Complexity: O(n ^ 2)
class Solution {
public:
    int n;
    vector<vector<long long>>preSum;
    vector<vector<vector<long long>>>dp;

    long long helper(int prevTaken,int prevLen,int col){
        if(col>n)   return 0;
        if(dp[prevTaken][prevLen][col]!=-1) return dp[prevTaken][prevLen][col];
        long long ans=0;
        for(int len=0;len<=n;len++){
            long long prevAns=0,currAns=0;
            if(prevTaken==0 && col>1 && len>prevLen)    prevAns=preSum[len][col-1]-preSum[prevLen][col-1];
            if(prevLen>len) currAns=preSum[prevLen][col]-preSum[len][col];
            long long ans1=currAns+prevAns+helper(1,len,col+1);
            long long ans2=prevAns+helper(0,len,col+1);
            ans=max(ans,max(ans1,ans2));
        }
        return dp[prevTaken][prevLen][col]=ans;
    }

    long long maximumScore(vector<vector<int>>& grid) {
        n=grid.size();
        preSum.assign(n+1,vector<long long>(n+1,0));
        dp.assign(2,vector<vector<long long>>(n+1,vector<long long>(n+1,-1)));
        for(int j=0;j<n;j++){
            for(int i=1;i<=n;i++){
                preSum[i][j+1]=preSum[i-1][j+1]+grid[i-1][j];
            }
        }
        return helper(0,0,1);
    }
};