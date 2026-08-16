#include<bits/stdc++.h>
using namespace std;

// Counting
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3]={0,0,0};
        for(int s:stones){
            f[s%3]++;
        }
        if(f[0]%2==0)   return min(f[1],f[2])>=1;
        return abs(f[1]-f[2])>=3;
    }
};