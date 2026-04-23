#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<long long>ans(n,0);
        for(auto &it:mpp){
            int m=it.second.size();
            long long leftSum=0;
            long long rightSum=0;
            for(int i=0;i<m;i++){
                rightSum+=it.second[i];
            }
            for(int i=0;i<m;i++){
                rightSum-=it.second[i];
                long long currSum=0;
                currSum+=(long long)it.second[i]*i-leftSum;
                currSum+=rightSum-(long long)(m-i-1)*it.second[i];
                leftSum+=it.second[i];
                ans[it.second[i]]=currSum;
            }
        }
        return ans;
    }
};