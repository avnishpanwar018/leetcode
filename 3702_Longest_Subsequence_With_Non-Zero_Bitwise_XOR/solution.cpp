#include<bits/stdc++.h>
using namespace std;

// Bit Manipulation / Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        bool allZero=true;
        for(int x:nums){
            total^=x;
            if(x>0) allZero=false;
        }
        if(total>0) return n;
        return allZero ? 0 : n-1;
    }
};