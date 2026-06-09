#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long mini=LLONG_MAX;
        long long maxi=LLONG_MIN;
        for(int n:nums){
            mini=min(mini,(long long)n);
            maxi=max(maxi,(long long)n);
        }
        return (maxi-mini)*k;
    }
};