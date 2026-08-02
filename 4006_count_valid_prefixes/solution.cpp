#include<bits/stdc++.h>
using namespace std;

// Prefix Frequency Counting
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int countValidPrefixes(string s) {
        int zero=0, one=0;
        int ans=0;
        for(char &c:s){
            if(c=='0')  zero++;
            else    one++;
            if(abs(zero-one)<=1)    ans++;
        }
        return ans;
    }
};