#include<bits/stdc++.h>
using namespace std;

// Stack
// Time Complexity: O(n)
// Space Complexity: O(n) auxiliary
class Solution1 {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c:s){
            if(c=='(') st.push(0);
            else{
                int x=st.top();
                st.pop();
                int score=(x==0) ? 1 : 2*x;
                st.top()+=score;
            }
        }
        return st.top();
    }
};

// Recursion
// Time Complexity: O(n)
// Space Complexity: O(n) auxiliary
class Solution2 {
public:
    int solve(string& s,int& i){
        int ans=0;
        while(i<s.size() && s[i]!=')'){
            if(s[i]=='('){
                i++;
                if(s[i]==')'){
                    i++;
                    ans+=1;
                }
                else{
                    int x=solve(s,i);
                    i++;
                    ans+=2*x;
                }
            }
        }
        return ans;
    }

    int scoreOfParentheses(string s) {
        int i=0;
        return solve(s,i);
    }
};

// Depth Counting
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary
class Solution3 {
public:
    int scoreOfParentheses(string s) {
        int ans=0,level=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') level++;
            else{
                level--;
                if(s[i-1]=='(') ans+=1<<level;
            }
        }
        return ans;
    }
};