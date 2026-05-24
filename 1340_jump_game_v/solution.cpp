#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * d)
// Space Complexity: O(n)
class Solution {
public:
    vector<int>jumps;

    int dfs(int idx,vector<int>&arr,int d){
        if(jumps[idx]!=-1)  return jumps[idx];
        jumps[idx]=1;
        for(int i=idx-1;i>=0 && idx-i<=d;i--){
            if(arr[i]<arr[idx]) jumps[idx]=max(jumps[idx],1+dfs(i,arr,d));
            else    break;
        }
        for(int i=idx+1;i<arr.size() && i-idx<=d;i++){
            if(arr[i]<arr[idx]) jumps[idx]=max(jumps[idx],1+dfs(i,arr,d));
            else    break;
        }
        return jumps[idx];
    }

    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        jumps.assign(n,-1);
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,dfs(i,arr,d));
        }
        return ans;
    }
};