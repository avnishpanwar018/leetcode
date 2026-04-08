#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(q * n)
// Space Complexity: O(1)
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD=1e9+7;
        for(auto q:queries){
            int idx=q[0];
            int r=q[1];
            int k=q[2];
            int v=q[3];
            while(idx<=r){
                long curr=nums[idx];
                nums[idx]=(int)((curr*v)%MOD);
                idx+=k;
            }
        }
        int ans=0;
        for(int n:nums){
            ans^=n;
        }
        return ans;
    }
};