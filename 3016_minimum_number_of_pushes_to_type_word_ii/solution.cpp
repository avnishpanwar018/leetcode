#include<bits/stdc++.h>
using namespace std;

// Greedy (Sorting)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=freq[i]*((i/8)+1);
        }
        return ans;
    }
};