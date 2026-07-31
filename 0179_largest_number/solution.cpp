#include<bits/stdc++.h>
using namespace std;

// Sorting (Custom Comparator)
// Time Complexity: O(n log n * d), where n = number of elements and d = maximum number of digits in an element
// Space Complexity: O(n * d)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>str;
        for(int n:nums){
            str.push_back(to_string(n));
        }
        sort(str.begin(),str.end(),[](const string &a,const string &b){
            return a+b > b+a;
        });
        if(str[0]=="0") return "0";
        string ans;
        for(string &s:str){
            ans+=s;
        }
        return ans;
    }
};