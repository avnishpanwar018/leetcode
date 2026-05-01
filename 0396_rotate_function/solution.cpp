#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int sum=0,fsum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            fsum+=i*nums[i];
        }
        int ans=fsum;
        for(int i=1;i<n;i++){
            fsum=fsum+sum-nums[n-i]*n;
            ans=max(ans,fsum);
        }
        return ans;
    }
};