#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n) worst case         O(log n) average case
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[high])    low=mid+1;
            else    high--;
        }
        return nums[low];
    }
};