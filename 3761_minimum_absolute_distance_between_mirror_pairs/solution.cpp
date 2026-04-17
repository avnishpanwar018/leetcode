#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * d)
// Space Complexity: O(n)
class Solution {
public:
    int reverseNum(int n){
        int ans=0;
        while(n>0){
            ans=ans*10+(n%10);
            n/=10;
        }
        return ans;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INT_MAX;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.count(nums[i]))  ans=min(ans,i-mpp[nums[i]]);
            int mirror=reverseNum(nums[i]);
            mpp[mirror]=i;
        }
        return ans==INT_MAX ? -1 : ans;
    }
};