#include<bits/stdc++.h>
using namespace std;

// Stack + Index Tracking
// Time Complexity: O(n)
// Space Complexity: O(n) auxiliary
class Solution1 {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else ans=max(ans,i-st.top());
            }       
        }
        return ans;
    }
};

// Two Pass + Counting
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary
class Solution2 {
public:
    int longestValidParentheses(string s) {
        int l=0,r=0,ans=0;
        for(char c:s){
            if(c=='(') l++;
            else r++;
            if(l==r) ans=max(ans,2*r);
            else if(r>l) l=r=0;
        }
        l=r=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') l++;
            else r++;
            if(l==r) ans=max(ans,2*l);
            else if(l>r) l=r=0;
        }
        return ans;
    }
};

// Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n) auxiliary
class Solution3 {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        vector<int> dp(n);
        int ans=0;
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1]=='(') dp[i]=(i>=2?dp[i-2]:0)+2;
                else if(i-dp[i-1]-1>=0 && s[i-dp[i-1]-1]=='(') dp[i]=dp[i-1]+2+(i-dp[i-1]>=2 ? dp[i-dp[i-1]-2] : 0);
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
};