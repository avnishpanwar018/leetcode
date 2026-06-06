#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>upper(26);
        vector<int>lower(26);
        for(char c:s){
            if(isupper(c))  upper[c-'A']++;
            else    lower[c-'a']++;
        }
        int ans=0;
        int odd=0;
        for(int i=0;i<26;i++){
            if(lower[i]%2!=0 || upper[i]%2!=0)  odd=1;
            ans+=2*(lower[i]/2);
            ans+=2*(upper[i]/2);
        }
        return ans+odd;
    }
};