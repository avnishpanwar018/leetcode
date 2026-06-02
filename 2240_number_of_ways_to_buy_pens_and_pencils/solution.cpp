#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(total/cost1)
// Space Complexity: O(1)
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans=0;
        for(int i=0;1LL*i*cost1<=total;i++){
            int remaining=total-i*cost1;
            ans+=(remaining/cost2)+1;
        }
        return ans;
    }
};