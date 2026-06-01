#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0;
        for(int i=0;i<cost.size();i++){
            if(i%3==0 || i%3==1)    ans+=cost[i];
        }
        return ans;
    }
};