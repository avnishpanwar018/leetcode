#include<bits/stdc++.h>
using namespace std;

// Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int l=0,r=0;
        vector<int>cnt(3,0);
        int ans=0;
        while(r<n){
            cnt[s[r]-'a']++;
            while(cnt[0] && cnt[1] && cnt[2]){
                ans+=n-r;
                cnt[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};


// Last Occurrence Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    int numberOfSubstrings(string s) {
        vector<int>last(3,-1);
        int ans=0;
        for(int i=0;i<s.size();i++){
            last[s[i]-'a']=i;
            ans+=1+min(last[0],min(last[1],last[2]));
        }
        return ans;
    }
};