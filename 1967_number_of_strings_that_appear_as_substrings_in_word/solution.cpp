#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m * k)    n = patterns.size(), m = average length of a pattern, k = word.size()
// Space Complexity: O(1)
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt=0;
        for(string &s:patterns){
            if(word.find(s)!=string::npos)  cnt++;
        }
        return cnt;
    }
};