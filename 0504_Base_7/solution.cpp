#include<bits/stdc++.h>
using namespace std;

// Repeated Division
// Time Complexity: O(log7|num|)
// Space Complexity: O(log7|num|)
class Solution1 {
public:
    string convertToBase7(int num) {
        bool neg=num<0;
        num=abs(num);
        string ans;
        while(num>=7){
            ans+=to_string(num%7);
            num/=7;
        }
        ans+=to_string(num);
        reverse(ans.begin(),ans.end());
        if(neg) ans='-'+ans;
        return ans;
    }
};

// Recursion + Repeated Division
// Time Complexity: O(log7|num|)
// Space Complexity: O(log7|num|)
class Solution2 {
public:
    string convertToBase7(int num) {
        bool neg=num<0;
        num=abs(num);
        string ans;
        function<void(int)> solve=[&](int n){
            if(n>=7) solve(n/7);
            ans+='0'+n%7;
        };
        solve(num);
        if(neg) ans='-'+ans;
        return ans;
    }
};