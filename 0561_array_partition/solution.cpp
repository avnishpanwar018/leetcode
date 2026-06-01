#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i+=2){
            ans+=nums[i];
        }
        return ans;
    }
};