#include<bits/stdc++.h>
using namespace std;

// Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(log n)   // recursion stack used by std::sort
class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return (nums[n-1]-1)*(nums[n-2]-1);
    }
};


// One Pass
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int maxProduct(vector<int>& nums) {
        int mx1=INT_MIN, mx2=INT_MIN;
        for(int n:nums){
            if(n>mx1){
                mx2=mx1;
                mx1=n;
            }
            else if(n>mx2)  mx2=n;
        }
        return (mx1-1) * (mx2-1);
    }
};