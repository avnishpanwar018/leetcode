#include<bits/stdc++.h>
using namespace std;

// Greedy (Sorting + Mirroring)
// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution1 {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1)    return s;
        string s1=s.substr(0,n/2);
        sort(s1.begin(),s1.end());
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return n%2==0 ? s1+s2 : s1+s[n/2]+s2;
    }
};

// Greedy (Counting Sort + Mirroring)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n/2;i++){
            freq[s[i]-'a']++;
        }
        string left;
        for(int i=0;i<26;i++){
            left.append(freq[i],'a'+i);
        }
        string right=left;
        reverse(right.begin(),right.end());
        return n%2==0 ? left+right : left+s[n/2]+right;
    }
};