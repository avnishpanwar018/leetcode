#include<bits/stdc++.h>
using namespace std;

// Sorting
// Time Complexity: O(d log d)
// Space Complexity: O(d)
class Solution1 {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return (s[s.size()-1]-'0') * (s[s.size()-2]-'0');
    }
};


// One-Pass (Track Two Largest Digits)
// Time Complexity: O(d)
// Space Complexity: O(1)
class Solution2 {
public:
    int maxProduct(int n) {
        int mx1=0, mx2=0;
        while(n){
            int d=n%10;
            if(d>=mx1){
                mx2=mx1;
                mx1=d;
            }
            else if(d>mx2)  mx2=d;
            n/=10;
        }
        return mx1*mx2;
    }
};