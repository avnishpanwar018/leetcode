#include<bits/stdc++.h>
using namespace std;

// Brute force
// Time Complexity: O(n^2)
// Space Complexity: O(1)
class Solution1 {
    public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j])    ans^=nums[i];
            }
        }
        return ans;
    }
};


// Unordered map
// Time Complexity: O(n) average, O(n^2) worst case
// Space Complexity: O(n)
class Solution2 {
    public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int n:nums){
            mpp[n]++;
        }
        int ans=0;
        for(auto it:mpp){
            if(it.second==2)    ans^=it.first;
        }
        return ans;
    }
};


// Frequency Array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution3 {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int>freq(51);
        for(int n:nums){
            freq[n]++;
        }
        int ans=0;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==2)  ans^=i;
        }
        return ans;
    }
};