#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    char processStr(string s, long long k) {
        long long len=0;
        for(char c:s){
            if(islower(c))  len++;
            else if(c=='*'){
                if(len>0)   len--;
            }
            else if(c=='#') len*=2;
            else if(c=='%'){}
        }
        if(k>=len)  return '.';
        for(int i=s.size()-1;i>=0;i--){
            if(islower(s[i])){
                if(k==len-1)    return s[i];
                len--;
            }
            else if(s[i]=='*')  len++;
            else if(s[i]=='#'){
                len/=2;
                if(k>=len)  k-=len;
            }
            else if(s[i]=='%')  k=len-k-1;
        }
        return '.';
    }
};