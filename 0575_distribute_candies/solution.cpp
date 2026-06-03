#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int>st(candyType.begin(),candyType.end());
        return min(candyType.size()/2,st.size());
    }
};