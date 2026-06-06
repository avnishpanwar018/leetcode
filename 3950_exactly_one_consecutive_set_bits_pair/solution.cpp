#include<bits/stdc++.h>
using namespace std;

// Using Binary String
// Time Complexity: O(log n)
// Space Complexity: O(log n)
class Solution1 {
    public:
    bool consecutiveSetBits(int n) {
        string s="";
        if(n==0)    s="0";
        while(n>0){
            s+=(n%2)+'0';
            n/=2;
        }
        int cnt=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1' && s[i-1]=='1')    cnt++;
        }
        return cnt==1;
    }
};



// Using Bit Manipulation
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution2 {
public:
    bool consecutiveSetBits(int n) {
        int cnt=0;
        while(n>0){
            if((n & 1) && ((n>>1) & 1)) cnt++;
            n>>=1;
        }
        return cnt==1;
    }
};