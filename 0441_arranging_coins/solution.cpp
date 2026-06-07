#include<bits/stdc++.h>
using namespace std;

// Simulation
// Time Complexity: O(√n)
// Space Complexity: O(1)
class Solution1 {
    public:
    int arrangeCoins(int n) {
        int rows=0;
        while(n-rows>0){
            rows++;
            n-=rows;
        }
        return rows;
    }
};



// Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution2 {
public:
    int arrangeCoins(int n) {
        long long low=0, high=n;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long coins=mid*(mid+1)/2;
            if(coins<=n)    low=mid+1;
            else    high=mid-1;
        }
        return high;
    }
};