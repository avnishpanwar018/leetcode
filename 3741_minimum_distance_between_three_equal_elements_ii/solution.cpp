#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,pair<int,int>>mpp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            if(mpp.count(x)){
                auto &p=mpp[x];
                if(p.second!=-1)    ans=min(ans,2*(i-p.second));
                p.second=p.first;
                p.first=i;
            }
            else    mpp[x]={i,-1};
        }
        return ans==INT_MAX ? -1 : ans;
    }
};