#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((n+q) * root n)
// Space Complexity: O(n+q)
class Solution {
public:
    const int MOD=1e9+7;

    int power(long long base,long long exp){
        long long ans=1;
        while(exp>0) {
            if(exp & 1) ans=(ans*base)%MOD;
            base=(base*base)%MOD;
            exp>>=1;
        }
        return (int)ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int k=sqrt(n);
        vector<vector<vector<int>>>blocks(k);
        for(auto& q:queries){
            int l=q[0],r=q[1],step=q[2],val=q[3];
            if(step<k)  blocks[step].push_back({l,r,val});
            else{
                while(l<=r){
                    nums[l]=(long long)nums[l]*val%MOD;
                    l+=step;
                }
            }
        }
        vector<long long>mul(n);
        for(int step=1;step<k;step++){
            if(blocks[step].empty())    continue;
            fill(mul.begin(),mul.end(),1);
            for(auto& q:blocks[step]){
                int l=q[0],r=q[1],val=q[2];
                mul[l]=mul[l]*val%MOD;
                int end=l+((r-l)/step+1)*step;
                if(end<n)   mul[end]=mul[end]*power(val,MOD-2)%MOD;
            }
            for(int i=step;i<n;i++){
                mul[i]=mul[i]*mul[i-step]%MOD;
            }
            for(int i=0;i<n;i++){
                nums[i]=(long long)nums[i]*mul[i]%MOD;
            }
        }
        int ans=0;
        for(int num:nums){
            ans^=num;
        }
        return ans;
    }
};