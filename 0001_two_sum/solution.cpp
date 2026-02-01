#include<bits/stdc++.h>
using namespace std;

// Brute force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;        
    }
};

// Hash map
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            int complement=target-nums[i];
            if(mp.count(complement)){
                return {mp[complement],i};
            }
            mp[nums[i]]=i;
        }
        return {};        
    }
};