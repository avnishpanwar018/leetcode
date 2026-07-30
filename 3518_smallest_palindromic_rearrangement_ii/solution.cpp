#include<bits/stdc++.h>
using namespace std;

// Greedy + Combinatorics
// Time Complexity: O(n * 26 * 26 * log k)
// Space Complexity: O(1) auxiliary, O(n) for output

class Solution {
public:
    long long nCr(int n,int r,int k){
        r=min(r,n-r);
        long long result=1;
        for(int i=1;i<=r;i++){
            result=result*(n-r+i)/i;
            if(result>=k)   return k;
        }
        return result;
    }

    string smallestPalindrome(string s, int k) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        char mid=' ';
        if(n%2!=0){
            mid=s[n/2];
            freq[mid-'a']--;
        }
        for(int i=0;i<26;i++){
            freq[i]/=2;
        }
        string firstHalf="";
        for(int i=0;i<n/2;i++){
            bool placedChar=false;
            for(int j=0;j<26;j++){
                if(freq[j]>0){
                    freq[j]--;
                    long long ways=1;
                    int letters=0;
                    for(int c=0;c<26;c++){
                        letters+=freq[c];
                    }
                    for(int c=0;c<26;c++){
                        if(freq[c]>0){
                            ways*=nCr(letters,freq[c],k);
                            letters-=freq[c];
                            if(ways>=k) break;
                        }
                    }
                    if(ways>=k){
                        placedChar=true;
                        firstHalf.push_back('a'+j);
                        break;
                    }
                    k-=ways;
                    freq[j]++;
                }
            }
            if(!placedChar) return "";
        }
        string secondHalf=firstHalf;
        reverse(secondHalf.begin(),secondHalf.end());
        return n&1 ? firstHalf + mid + secondHalf : firstHalf + secondHalf;
    }
};