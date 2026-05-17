#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        queue<int>q;
        vector<bool>visited(n,false);
        q.push(start);
        visited[start]=true;
        while(!q.empty()){
            int i=q.front();
            q.pop();
            if(arr[i]==0)   return true;
            for(int next:{i+arr[i],i-arr[i]}){
                if(next>=0 && next<n && !visited[next]){
                    q.push(next);
                    visited[next]=true;
                }
            }
        }
        return false;
    }
};