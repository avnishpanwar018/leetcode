#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n ^ 2)
// Space Complexity: O(n)
class Solution {
public:
    vector<int>dp;

    int helper(int idx,vector<int>&nums,int target){
        if(idx==nums.size()-1)  return 0;
        if(dp[idx]!=-2) return dp[idx];
        int ans=-1;
        for(int i=idx+1;i<nums.size();i++){
            if(abs(nums[i]-nums[idx])<=target){
                int next=helper(i,nums,target);
                if(next!=-1)    ans=max(ans,next+1);
            }
        }
        return dp[idx]=ans;
    }

    int maximumJumps(vector<int>& nums, int target) {
        dp.assign(nums.size(),-2);
        return helper(0,nums,target);
    }
};