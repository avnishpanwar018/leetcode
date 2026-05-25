#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.size();
        if(s[n-1]=='1') return false;
        vector<int>arr(n);
        int count=0;
        for(int i=0;i<n;i++){
            count+=arr[i];
            if(i==0 || s[i]=='0' && count>0){
                if(i+minJump<n) arr[i+minJump]+=1;
                if(i+maxJump+1<n)   arr[i+maxJump+1]-=1;
            }
        }
        return count>0;
    }
};