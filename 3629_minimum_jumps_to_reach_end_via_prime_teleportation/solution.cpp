#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * sqrt(v) + v)      v=max(nums[i])
// Space Complexity: O(n)
class Solution {
public:
    bool isPrime(int n){
        if(n<2) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)  return false;
        }
        return true;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size();
        if(n==1)    return 0;
        unordered_map<int,vector<int>>mpp;
        int maxi=0;
        for(int i=0;i<n;i++){
            mpp[nums[i]].push_back(i);
            maxi=max(maxi,nums[i]);
        }
        vector<int>dist(n,-1);
        queue<int>q;
        q.push(0);
        dist[0]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vector<int>temp;
            if(curr-1>=0)   temp.push_back(curr-1);
            if(curr+1<n)    temp.push_back(curr+1);
            if(isPrime(nums[curr])){
                int p=nums[curr];
                for(int val=p;val<=maxi;val+=p){
                    if(mpp.count(val)){
                        for(int idx:mpp[val]){
                            temp.push_back(idx);
                        }
                        mpp.erase(val);
                    }
                }
            }
            for(int it:temp){
                if(dist[it]==-1){
                    dist[it]=dist[curr]+1;
                    if(it==n-1) return dist[it];
                    q.push(it);
                }
            }
        }
        return dist[n-1];
    }
};