#include<bits/stdc++.h>
using namespace std;

// Frequency Array (Hashing)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n+1,0);
        vector<int>ans(n,0);
        int common=0;
        for(int i=0;i<n;i++){
            freq[A[i]]++;
            if(freq[A[i]]==2)   common++;
            freq[B[i]]++;
            if(freq[B[i]]==2)   common++;
            ans[i]=common;
        }
        return ans;
    }
};

// Bitmask
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        long long a=0,b=0;
        int n=A.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            a = a | (1LL << A[i]);
            b = b | (1LL << B[i]);
            ans[i]=__builtin_popcountll(a & b);
        }
        return ans;
    }
};