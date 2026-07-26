#include<bits/stdc++.h>
using namespace std;

// Greedy
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    int largestInteger(int n, int s) {
        if(s>9*n)   return -1;
        string ans="";
        for(int i=0;i<n;i++){
            int d=min(9,s);
            ans+=d+'0';
            s-=d;
        }
        return stoi(ans);
    }
};


// Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int largestInteger(int n, int s) {
        if(s>9*n)   return -1;
        int ans=0;
        for(int i=0;i<n;i++){
            int d=min(9,s);
            ans=ans*10+d;
            s-=d;
        }
        return ans;
    }
};