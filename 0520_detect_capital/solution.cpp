#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
    public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        bool capital=isupper(word[n-1]);
        for(int i=n-2;i>0;i--){
            if(isupper(word[i]) && !capital)    return false;
            else if(!isupper(word[i]) && capital)   return false;
        }
        if(!isupper(word[0]) && capital)    return false;
        return true;
    }
};



// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    bool detectCapitalUse(string word) {
        int caps=0;
        for(char c:word){
            if(isupper(c))  caps++;
        }
        return caps==word.size() || caps==0 || (caps==1 && isupper(word[0]));
    }
};