#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + q)
// Space Complexity: O(n + q)
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
        }
        vector<int>temp(n,-1);
        for(auto &it:mpp){
            int len=it.second.size();
            if(len==1)  continue;
            for(int i=0;i<len;i++){
                int curr=it.second[i];
                int prev=it.second[(i-1+len)%len];
                int next=it.second[(i+1)%len];
                int d1=min(abs(curr-prev),n-abs(curr-prev));
                int d2=min(abs(curr-next),n-abs(curr-next));
                temp[curr]=min(d1,d2);
            }
        }
        vector<int>ans;
        for(int q:queries){
            ans.push_back(temp[q]);
        }
        return ans;
    }
};