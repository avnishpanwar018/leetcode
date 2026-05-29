#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log m)
// Space Complexity: O(1)
class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int n:nums){
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};