#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>freq,cntFreq;
            int maxf=0;
            for(int j=i;j<n;j++){
                int x=nums[j];
                int oldf=freq[x];
                if(oldf>0){
                    if(--cntFreq[oldf]==0)  cntFreq.erase(oldf);
                }
                int newf=++freq[x];
                cntFreq[newf]++;
                maxf=max(maxf,newf);
                int distinct=freq.size();
                bool ok=false;
                if(distinct==1) ok=true;
                else if(maxf%2==0){
                    if(cntFreq.size()==2 && cntFreq.count(maxf) && cntFreq.count(maxf/2))     ok=true;
                }
                if(ok)  ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};