#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int diff=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target) diff=min(diff,abs(i-start));
        }
        return diff;
    }
};