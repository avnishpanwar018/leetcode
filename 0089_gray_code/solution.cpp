#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n) auxiliary
//                   O(2^n) including output
class Solution1 {
public:
    string toBinary(int n){
        if(n==0)    return "0";
        string s="";
        while(n>0){
            s+=to_string(n%2);
            n/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }

    int toDecimal(string s){
        int p=1;
        int n=0;
        for(int i=s.size()-1;i>=0;i--){
            n+=(s[i]-'0')*p;
            p*=2;
        }
        return n;
    }

    string toGray(string s){
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++){
            ans+=((s[i-1]-'0') ^ (s[i]-'0'))+'0';
        }
        return ans;
    }

    vector<int> grayCode(int n) {
        vector<int>ans;
        for(int i=0;i<(1<<n);i++){
            string bin=toBinary(i);
            if(bin.size()<n){
                bin.insert(0,n-bin.size(),'0');
            }
            string gray=toGray(bin);
            ans.push_back(toDecimal(gray));
        }
        return ans;
    }
};



// Time Complexity: O(2^n)
// Space Complexity: O(1) auxiliary
//                   O(2^n) including output
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int>ans;
        for(int i=0;i<(1<<n);i++){
            ans.push_back(i^(i>>1));
        }
        return ans;
    }
};