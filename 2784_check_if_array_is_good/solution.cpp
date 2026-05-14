#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution1 {
public:
bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        if(nums[n]!=n)  return false;
        for(int i=0;i<n-1;i++){
            if(nums[i]!=i+1)    return false;
        }
        return nums[n-1]==n;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
    public:
    bool isGood(vector<int>& nums) {
        int n=nums.size()-1;
        vector<int>freq(n+1);
        for(int x:nums){
            if(x>n) return false;
            freq[x]++;
        }
        for(int i=1;i<n;i++){
            if(freq[i]!=1) return false;
        }
        return freq[n]==2;
    }
};