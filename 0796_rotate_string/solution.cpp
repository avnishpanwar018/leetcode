#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n ^ 2)
// Space Complexity: O(1)
class Solution1 {
    public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        for(int i=0;i<s.size();i++){
            s.push_back(s[0]);
            s.erase(s.begin());
            if(s==goal) return true;
        }
        return false;
    }
};



// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())   return false;
        return (s+s).find(goal)!=string::npos;
    }
};