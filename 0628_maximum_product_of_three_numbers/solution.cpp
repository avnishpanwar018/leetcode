#include<bits/stdc++.h>
using namespace std;

// Greedy (Sorting)
// Time Complexity: O(n log n)
// Auxiliary Space: O(log n)   // recursion stack of std::sort (introsort)
// Total Space: O(log n)
class Solution1 {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return max(nums.back()*nums[nums.size()-2]*nums[nums.size()-3],nums.back()*nums.front()*nums[1]);
    }
};

// Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int maximumProduct(vector<int>& nums) {
        int max1,max2,max3,min1,min2;
        max1=max2=max3=INT_MIN;
        min1=min2=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max1){
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
            else if(nums[i]>max2){
                max3=max2;
                max2=nums[i];
            }
            else if(nums[i]>max3){
                max3=nums[i];
            }
            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }
            else if(nums[i]<min2){
                min2=nums[i];
            }
        }
        return max(max1*max2*max3,min1*min2*max1);        
    }
};