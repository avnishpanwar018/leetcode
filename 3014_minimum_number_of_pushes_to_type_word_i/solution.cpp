#include<bits/stdc++.h>
using namespace std;

// Greedy (Simulation)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int minimumPushes(string word) {
        int ans=0;
        int cnt=0;
        int push=1;
        for(int i=0;i<word.size();i++){
            ans+=push;
            cnt++;
            if(cnt==8){
                push++;
                cnt=0;
            }
        }
        return ans;
    }
};


// Greedy (Mathematical Observation)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int minimumPushes(string word) {
        int ans=0;
        for(int i=0;i<word.size();i++){
            ans+=i/8+1;
        }
        return ans;
    }
};


// Greedy (Case Analysis)
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution3 {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<=8)    return n;
        else if(n<=16)  return 8+(n-8)*2;
        else if(n<=24)  return 8+16+(n-16)*3;
        return 8+16+24+(n-24)*4;
    }
};