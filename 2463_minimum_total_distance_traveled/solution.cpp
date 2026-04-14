#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m * l)
// Space Complexity: O(n * m)
class Solution {
public:
    vector<vector<long long>>dp;
    const long long INF=1e18;

    long long helper(vector<int>&robot,vector<vector<int>>&factory,int rindex,int findex){
        if(rindex==robot.size())    return 0;
        if(findex==factory.size())  return INF;
        if(dp[rindex][findex]!=-1)  return dp[rindex][findex];
        long long skip=helper(robot,factory,rindex,findex+1);
        long long dist=0;
        long long ans=INF;
        for(int i=0;i<factory[findex][1] && rindex+i<robot.size();i++){
            dist+=abs(robot[rindex+i]-factory[findex][0]);
            long long next=helper(robot,factory,rindex+i+1,findex+1);
            if(next!=INF) ans=min(ans,dist+next);
        }
        return dp[rindex][findex]=min(skip,ans);
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        dp.assign(robot.size(),vector<long long>(factory.size(),-1));
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        return helper(robot,factory,0,0);
    }
};