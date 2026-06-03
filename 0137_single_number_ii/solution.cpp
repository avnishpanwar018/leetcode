#include<bits/stdc++.h>
using namespace std;

// Using Set
// Time Complexity: O(n * log n)
// Space Complexity: O(n)
class Solution1 {
    public:
    int singleNumber(vector<int>& nums) {
        set<int>st;
        long long totalSum=0;
        for(int n:nums){
            st.insert(n);
            totalSum+=n;
        }
        long long uniqueSum=0;
        for(int n:st){
            uniqueSum+=n;
        }
        return (3*uniqueSum-totalSum)/2;
    }
};



// Using Unordered Set
// Time Complexity: O(n) average
// Space Complexity: O(n)
class Solution2 {
    public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int>st;
        long long totalSum=0;
        for(int n:nums){
            st.insert(n);
            totalSum+=n;
        }
        long long uniqueSum=0;
        for(int n:st){
            uniqueSum+=n;
        }
        return (3*uniqueSum-totalSum)/2;
    }
};



// Using Bit Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int bit=0;bit<32;bit++){
            int count=0;
            for(int n:nums){
                if((n>>bit) & 1)    count++;
            }
            if(count%3) ans|=1<<bit;
        }
        return ans;
    }
};