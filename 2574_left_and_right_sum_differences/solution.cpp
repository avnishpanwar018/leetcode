#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary, O(n) for output
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        long leftSum=0, rightSum=0;
        for(int n:nums){
            rightSum+=n;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            rightSum-=nums[i];
            ans.push_back(abs(leftSum-rightSum));
            leftSum+=nums[i];
        }
        return ans;
    }
};