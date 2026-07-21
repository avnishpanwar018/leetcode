#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        vector<int>zeroBlocks;
        int activeCount=count(begin(s),end(s),'1');
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                zeroBlocks.push_back(i-start);
            }
            else    i++;
        }
        int maxGain=0;
        for(int i=1;i<zeroBlocks.size();i++){
            maxGain=max(maxGain,zeroBlocks[i]+zeroBlocks[i-1]);
        }
        return maxGain+activeCount;
    }
};


// Space Optimization
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int activeCount=count(begin(s),end(s),'1');
        int prevZeroBlock=0;
        int maxGain=0;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start=i;
                while(i<n && s[i]=='0'){
                    i++;
                }
                int currZeroBlock=i-start;
                if(prevZeroBlock!=0)    maxGain=max(maxGain,prevZeroBlock+currZeroBlock);
                prevZeroBlock=currZeroBlock;
            }
            else    i++;
        }
        return maxGain+activeCount;
    }
};