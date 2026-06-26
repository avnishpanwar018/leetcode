#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int len=2*n+2;
        vector<long long>cnt(len),pref(len);
        int idx=n+1;
        cnt[idx]=1;
        pref[idx]=1;
        long long ans=0;
        for(int num:nums){
            if(num==target) idx++;
            else    idx--;
            cnt[idx]++;
            ans+=pref[idx-1];
            pref[idx]=pref[idx-1]+cnt[idx];
        }
        return ans;
    }
};