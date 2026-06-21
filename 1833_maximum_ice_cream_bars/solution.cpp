#include<bits/stdc++.h>
using namespace std;

// Sorting + Greedy
// Time Complexity: O(n log n)
// Space Complexity: O(log n)       // due to sort() recursion stack
class Solution1 {
    public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int i=0;
        while(i<costs.size() && coins>=costs[i]){
            coins-=costs[i];
            i++;
        }
        return i;
    }
};


// Counting Sort + Greedy
// Time Complexity: O(n + m)
// Space Complexity: O(m)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int>freq(100001,0);
        for(int cost:costs){
            freq[cost]++;
        }
        int ans=0;
        for(int cost=1;cost<=100000;cost++){
            if(freq[cost]==0)   continue;
            int canBuy=min(freq[cost],coins/cost);
            ans+=canBuy;
            coins-=canBuy*cost;
            if(coins<cost)  break;
        }
        return ans;
    }
};