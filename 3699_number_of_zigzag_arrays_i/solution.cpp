#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * m)
// Space Complexity: O(m)
class Solution {
public:
    const int MOD=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<long long>up(m),down(m);
        for(int i=0;i<m;i++){
            up[i]=m-i-1;
            down[i]=i;
        }
        vector<long long>prefUp(m),prefDown(m);
        vector<long long> newUp(m), newDown(m);
        for(int pos=n-2;pos>=1;pos--){
            prefUp[0]=up[0];
            prefDown[0]=down[0];
            for(int i=1;i<m;i++){
                prefUp[i]=(prefUp[i-1]+up[i])%MOD;
                prefDown[i]=(prefDown[i-1]+down[i])%MOD;
            }
            for(int i=0;i<m;i++){
                long long greaterSum=(prefDown[m-1]-prefDown[i]+MOD)%MOD;
                long long smallerSum= i>0 ? prefUp[i-1] : 0;
                newUp[i]=greaterSum;
                newDown[i]=smallerSum;
            }
            up.swap(newUp);
            down.swap(newDown);
        }
        long long ans=0;
        for(int i=0;i<m;i++){
            ans=(ans+up[i]+down[i])%MOD;
        }
        return (int)ans;
    }
};