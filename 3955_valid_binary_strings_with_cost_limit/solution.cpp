#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(F(n+2) * n)   where F(i) is the i-th Fibonacci number
// Space Complexity: O(n) auxiliary, O(F(n+2) * n) including output
class Solution {
public:
    void solve(int idx,string &s,vector<string>&ans,int cost,int n,int k){
        if(s.size()==n){
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        solve(idx+1,s,ans,cost,n,k);
        s.pop_back();
        if((s.empty() || s.back()!='1') && (cost+idx<=k)){
            s.push_back('1');
            solve(idx+1,s,ans,cost+idx,n,k);
            s.pop_back();
        }
        return;
    }
    
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string s="";
        solve(0,s,ans,0,n,k);
        return ans;
    }
};