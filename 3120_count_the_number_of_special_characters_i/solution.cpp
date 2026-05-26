#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool>lower(26);
        vector<bool>upper(26);
        for(char &c:word){
            if(c>='a' && c<='z')    lower[c-'a']=true;
            else if(c>='A' && c<='Z')   upper[c-'A']=true;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(lower[i] && upper[i])    ans++;
        }
        return ans;
    }
};