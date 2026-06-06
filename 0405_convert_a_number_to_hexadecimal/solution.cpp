#include<bits/stdc++.h>
using namespace std;

// Using Manual Mapping
// Time Complexity: O(log n) or O(1) for a 32-bit integer (at most 8 iterations)
// Space Complexity: O(1)
class Solution1 {
    public:
    string toHex(int num) {
        if(num==0)  return "0";
        string s="";
        unsigned int n=num;
        while(n>0){
            int rem=n%16;
            if(rem<10)  s+=to_string(rem);
            else    s+=(rem-10)+'a';
            n/=16;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};


// Using Lookup Table
// Time Complexity: O(log n) or O(1) for a 32-bit integer (at most 8 iterations)
// Space Complexity: O(1)
class Solution2 {
public:
    string toHex(int num) {
        if(num==0)  return "0";
        string hex="0123456789abcdef";
        string s="";
        unsigned int n=num;
        while(n>0){
            s+=hex[n%16];
            n/=16;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};