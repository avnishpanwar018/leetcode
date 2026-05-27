#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        vector<int>lower(26,-1);
        vector<int>upper(26,-1);
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z')    lower[word[i]-'a']=i;
        }
        for(int i=n-1;i>=0;i--){
            if(word[i]>='A' && word[i]<='Z')    upper[word[i]-'A']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(lower[i]>=0 && upper[i]>=0 && lower[i]<upper[i]) ans++;
        }
        return ans;
    }
};