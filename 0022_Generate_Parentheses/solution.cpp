#include<bits/stdc++.h>
using namespace std;

// Brute Force + Validation
// Time Complexity: O(n * 4^n)
// Space Complexity: O(n) auxiliary
class Solution1 {
public:
    vector<string> ans;

    bool valid(string s){
        int cnt=0;
        for(char c:s){
            if(c=='(') cnt++;
            else cnt--;
            if(cnt<0) return false;
        }
        return cnt==0;
    }

    void generate(string s,int n){
        if(s.size()==2*n){
            if(valid(s)) ans.push_back(s);
            return;
        }
        s+='(';
        generate(s,n);
        s.back()=')';
        generate(s,n);
    }

    vector<string> generateParenthesis(int n) {
        generate("",n);
        return ans;
    }
};

// Backtracking / DFS
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(n) auxiliary
class Solution2 {
public:
    vector<string>ans;
    string s;

    void dfs(int open,int close){
        if(open==0 && close==0){
            ans.push_back(s);
            return;
        }
        if(open>0){
            s+='(';
            dfs(open-1,close);
            s.pop_back();
        }
        if(close>open){
            s+=')';
            dfs(open,close-1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        dfs(n,n);
        return ans;
    }
};

// Dynamic Programming (Catalan DP)
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(4^n * sqrt(n))
class Solution3 {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                for(string left:dp[j]){
                    for(string right:dp[i-1-j]){
                        dp[i].push_back("("+left+")"+right);
                    }
                }
            }
        }
        return dp[n];
    }
};

// BFS / Iterative Backtracking
// Time Complexity: O(4^n / sqrt(n))
// Space Complexity: O(4^n * sqrt(n))
class Solution4 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        queue<tuple<string,int,int>> q;
        q.push({"",0,0});
        while(!q.empty()){
            auto [s,open,close]=q.front();
            q.pop();
            if(s.size()==2*n){
                ans.push_back(s);
                continue;
            }
            if(open<n) q.push({s+"(",open+1,close});
            if(close<open) q.push({s+")",open,close+1});
        }
        return ans;
    }
};