#include<bits/stdc++.h>
using namespace std;

// Using set
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution1 {
    public:
    int passwordStrength(string password) {
        set<char>st(password.begin(),password.end());
        int ans=0;
        for(char c:st){
            if(c>='a' && c<='z')    ans+=1;
            else if(c>='A' && c<='Z')   ans+=2;
            else if(c>='0' && c<='9')   ans+=3;
            else    ans+=5;
        }
        return ans;
    }
};



// Using unordered set
// Time Complexity: O(n) average, O(n^2) worst case
// Space Complexity: O(n)
class Solution2 {
    public:
    int passwordStrength(string password) {
        unordered_set<char>st(password.begin(),password.end());
        int ans=0;
        for(char c:st){
            if(c>='a' && c<='z')    ans+=1;
            else if(c>='A' && c<='Z')   ans+=2;
            else if(c>='0' && c<='9')   ans+=3;
            else    ans+=5;
        }
        return ans;
    }
};



// Using frequency array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution3 {
    public:
    int passwordStrength(string password) {
        vector<bool>freq(256,false);
        for(char c:password){
            freq[c]=true;
        }
        int ans=0;
        for(int c=0;c<256;c++){
            if(!freq[c])    continue;
            if(islower(c))  ans+=1;
            else if(isupper(c)) ans+=2;
            else if(isdigit(c)) ans+=3;
            else    ans+=5;
        }
        return ans;
    }
};