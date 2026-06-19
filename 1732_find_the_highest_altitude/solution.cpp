#include<bits/stdc++.h>
using namespace std;

// Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
    public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>preSum(n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            preSum[i]=preSum[i-1]+gain[i-1];
            ans=max(ans,preSum[i]);
        }
        return ans;
    }
};



// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0, ans=0;
        for(int x:gain){
            curr+=x;
            ans=max(ans,curr);
        }
        return ans;
    }
};