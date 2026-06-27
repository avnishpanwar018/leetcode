#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log m)
// Space Complexity: O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int>mpp;
        int ones=0;
        for(int n:nums){
            mpp[n]++;
            if(n==1)    ones++;
        }
        int ans=(ones%2==0) ? ones-1 : ones;
        mpp.erase(1LL);
        for(auto &it:mpp){
            int cnt=0;
            long long curr=it.first;
            while(mpp.count(curr)){
                if(mpp[curr]>=2)    cnt+=2;
                else{
                    cnt++;
                    break;
                }
                curr=curr*curr;
            }
            if(cnt%2==0)    cnt--;
            ans=max(ans,cnt);
        }
        return ans;
    }
};