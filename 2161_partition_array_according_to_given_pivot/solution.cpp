#include<bits/stdc++.h>
using namespace std;

// Three Arrays
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>small, equal, large;
        for(int n:nums){
            if(n<pivot) small.push_back(n);
            else if(n==pivot)   equal.push_back(n);
            else    large.push_back(n);
        }
        vector<int>ans;
        for(int n:small)    ans.push_back(n);
        for(int n:equal)    ans.push_back(n);
        for(int n:large)    ans.push_back(n);
        return ans;
    }
};


// Three Passes
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        for(int n:nums){
            if(n<pivot) ans.push_back(n);
        }
        for(int n:nums){
            if(n==pivot)    ans.push_back(n);
        }
        for(int n:nums){
            if(n>pivot) ans.push_back(n);
        }
        return ans;
    }
};


// Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
    public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int>ans(n);
        int left=0, right=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)   ans[left++]=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]>pivot)   ans[right--]=nums[i];
        }
        while(left<=right){
            ans[left++]=pivot;
        }
        return ans;
    }
};