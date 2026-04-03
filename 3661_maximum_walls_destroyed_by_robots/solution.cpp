#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n logn + m logm + n logm)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>>t;

    int countWalls(vector<int>&walls,int l,int r){
        int left=lower_bound(walls.begin(),walls.end(),l)-walls.begin();
        int right=upper_bound(walls.begin(),walls.end(),r)-walls.begin();
        return right-left;
    }

    int solve(vector<int>&walls,vector<pair<int,int>>&roboDist,vector<pair<int,int>>&range,int i,int prevDir){
        if(i==roboDist.size())  return 0;
        if(t[i][prevDir]!=-1)   return t[i][prevDir];
        int leftStart=range[i].first;
        if(prevDir==1 && i>0)   leftStart=max(leftStart,range[i-1].second+1);
        int leftTake=countWalls(walls,leftStart,roboDist[i].first)+solve(walls,roboDist,range,i+1,0);
        int rightTake=countWalls(walls,roboDist[i].first,range[i].second)+solve(walls,roboDist,range,i+1,1);
        return t[i][prevDir]=max(leftTake,rightTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n=robots.size();
        vector<pair<int,int>>roboDist(n);
        for(int i=0;i<n;i++){
            roboDist[i]={robots[i],distance[i]};
        }
        sort(roboDist.begin(),roboDist.end());
        sort(walls.begin(),walls.end());
        vector<pair<int,int>>range(n);
        for(int i=0;i<n;i++){
            int pos=roboDist[i].first;
            int d=roboDist[i].second;
            int leftLimit=(i==0) ? 1: roboDist[i-1].first+1;
            int rightLimit=(i==n-1) ? 1e9 : roboDist[i+1].first-1;
            int l=max(pos-d,leftLimit);
            int r=min(pos+d,rightLimit);
            range[i]={l,r};
        }
        t.assign(n+1,vector<int>(2,-1));
        return solve(walls,roboDist,range,0,0);
    }
};