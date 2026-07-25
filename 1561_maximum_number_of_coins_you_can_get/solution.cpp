#include<bits/stdc++.h>
using namespace std;

// Greedy (Sorting + Two Pointers)
// Time Complexity: O(n log n)
// Space Complexity: O(log n)       // recursion stack of std:sort()
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int ans=0;
        int left=0;
        int right=piles.size()-1;
        while(left<right){
            right--;
            ans+=piles[right];
            right--;
            left++;
        }
        return ans;
    }
};