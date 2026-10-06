#include<bits/stdc++.h>
using namespace std;

// Stack
// Time Complexity: O(n)
// Space Complexity: O(n) auxiliary
class Solution1 {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(char c:s){
            if(c=='(') st.push(c);
            else{
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(c);
            }
        }
        return st.size();
    }
};

// Greedy / Balance Counting
// Time Complexity: O(n)
// Space Complexity: O(1) auxiliary
class Solution2 {
public:
    int minAddToMakeValid(string s) {
        int open=0, add=0;
        for(char c:s){
            if(c=='(') open++;
            else{
                if(open) open--;
                else add++;
            }
        }
        return open+add;
    }
};