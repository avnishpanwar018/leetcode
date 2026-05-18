#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[arr[i]].push_back(i);
        }
        queue<int>q;
        q.push(0);
        vector<int>dist(n,-1);
        dist[0]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==n-1)   return dist[curr];
            if(curr-1>=0 && dist[curr-1]==-1){
                dist[curr-1]=dist[curr]+1;
                q.push(curr-1);
            }
            if(curr+1<n && dist[curr+1]==-1){
                dist[curr+1]=dist[curr]+1;
                q.push(curr+1);
            }
            for(int i:mpp[arr[curr]]){
                if(dist[i]==-1){
                    dist[i]=dist[curr]+1;
                    q.push(i);
                }
            }
            mpp[arr[curr]].clear();
        }
        return dist[n-1];
    }
};