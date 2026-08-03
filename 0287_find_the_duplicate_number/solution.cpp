#include<bits/stdc++.h>
using namespace std;

// Binary Search on Answer
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int low=1;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
            int cnt=0;
            for(int n:nums){
                if(n<=mid)  cnt++;
            }
            if(cnt>mid) high=mid;
            else    low=mid+1;
        }
        return low;
    }
};


// Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        slow=nums[0];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};