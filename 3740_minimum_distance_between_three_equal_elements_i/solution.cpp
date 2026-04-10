#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:mpp){
            if(it.second.size()<3)   continue;
            vector<int>temp=it.second;
            for(int i=0;i<temp.size()-2;i++){
                int x=temp[i+1]-temp[i];
                int y=temp[i+2]-temp[i+1];
                int z=temp[i+2]-temp[i];
                ans=min(ans,x+y+z);
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};