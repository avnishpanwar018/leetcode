#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^n)
// Space Complexity: O(2^n)
class Solution {
public:
    string processStr(string s) {
        string ans="";
        for(char c:s){
            if(islower(c))  ans+=c;
            else if(c=='*' && !ans.empty()) ans.pop_back();
            else if(c=='#') ans+=ans;
            else if(c=='%') reverse(ans.begin(),ans.end());
        }
        return ans;
    }
};