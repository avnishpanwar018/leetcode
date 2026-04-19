#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + m)
// Space Complexity: O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        int i=0,j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans=max(ans,j-i);
                j++;
            }
            else    i++;
        }
        return ans;
    }
};