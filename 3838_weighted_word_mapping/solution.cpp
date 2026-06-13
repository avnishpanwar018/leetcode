#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(n)
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string word:words){
            int sum=0;
            for(char c:word){
                sum+=weights[c-'a'];
            }
            sum%=26;
            ans+='z'-sum;
        }
        return ans;
    }
};