#include<bits/stdc++.h>
using namespace std;

// Sorting (Greedy)
// Time Complexity: O(n log n)
// Space Complexity: O(log n)       // recursion stack of sort() 
class Solution1 {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if(arr[0]!=1)   arr[0]=1;
        for(int i=1;i<n;i++){
            if(abs(arr[i]-arr[i-1])<=1) continue;
            arr[i]=arr[i-1]+1;
        }
        return arr[n-1];
    }
};



// Counting Sort (Greedy)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>cnt(n+1);
        for(int x:arr){
            cnt[min(x,n)]++;
        }
        int ans=1;
        for(int i=2;i<=n;i++){
            ans=min(i,ans+cnt[i]);
        }
        return ans;
    }
};