#include<bits/stdc++.h>
using namespace std;

// Simulation (Two Traversals)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(nums[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};


// Simulation (Single Traversal)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(2*n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
            ans[i+n]=nums[n-i-1];
        }
        return ans;
    }
};


// Simulation (STL)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        vector<int>ans=nums;
        ans.insert(ans.end(),nums.rbegin(),nums.rend());
        return ans;
    }
};