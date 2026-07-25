#include<bits/stdc++.h>
using namespace std;

// Greedy (Sorting + Comparison)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected(heights);
        sort(expected.begin(),expected.end());
        int cnt=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=expected[i]) cnt++;
        }
        return cnt;
    }
};