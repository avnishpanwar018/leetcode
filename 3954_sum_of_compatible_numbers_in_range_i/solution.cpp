#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(k)
// Space Complexity: O(1)
class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int ans=0;
        for(int i=max(1,n-k);i<=n+k;i++){
            if((abs(n-i)<=k) && (n & i)==0) ans+=i;
        }
        return ans;
    }
};