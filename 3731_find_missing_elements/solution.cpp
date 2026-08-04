#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(n * range)
// Space Complexity: O(1)
class Solution1 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest=*min_element(nums.begin(),nums.end());
        int largest=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=smallest;i<=largest;i++){
            bool found=false;
            for(int x:nums){
                if(i==x){
                    found=true;
                    break;
                }
            }
            if(!found)  ans.push_back(i);
        }
        return ans;
    }
};


// Hashing (unordered_set)
// Average Time Complexity: O(n + range)
// Space Complexity: O(n)
class Solution2 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int smallest=*min_element(nums.begin(),nums.end());
        int largest=*max_element(nums.begin(),nums.end());
        unordered_set<int>st(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=smallest;i<=largest;i++){
            if(!st.count(i))    ans.push_back(i);
        }
        return ans;
    }
};


// Sorting
// Time Complexity: O(n log n + k), where k = no. of missing elements
// Space Complexity: O(log n) auxiliary
class Solution3 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            for(int j=nums[i-1]+1;j<nums[i];j++){
                ans.push_back(j);
            }
        }
        return ans;
    }
};


// Boolean Array (Frequency Array)
// Time Complexity: O(n + range)
// Space Complexity: O(1)
class Solution4 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool>present(101,false);
        int mn=101, mx=0;
        for(int x:nums){
            present[x]=true;
            mn=min(mn,x);
            mx=max(mx,x);
        }
        vector<int>ans;
        for(int i=mn;i<=mx;i++){
            if(!present[i]) ans.push_back(i);
        }
        return ans;
    }
};