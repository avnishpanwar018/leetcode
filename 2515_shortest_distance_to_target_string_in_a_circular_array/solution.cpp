#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m) due to string comparison
// Space Complexity: O(1)
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int d1=abs(startIndex-i);
                int d2=n-d1;
                ans=min(ans,min(d1,d2));
            }
        }
        return ans==INT_MAX ? -1 : ans;
    }
};