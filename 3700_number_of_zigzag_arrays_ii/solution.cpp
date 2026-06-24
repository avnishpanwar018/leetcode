#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m^3 log n)
// Space Complexity: O(m^2)
class Solution {
    const int MOD=1e9+7;

    vector<vector<long long>>matPow(vector<vector<long long>>base,long long exp){
        int m=base.size();
        vector<vector<long long>>res(m,vector<long long>(m));
        for(int i=0;i<m;i++)res[i][i]=1;
        while(exp){
            if(exp&1)res=multiply(res,base);
            base=multiply(base,base);
            exp>>=1;
        }
        return res;
    }
    
    vector<vector<long long>>multiply(vector<vector<long long>>&A,vector<vector<long long>>&B){
        int m=A.size();
        vector<vector<long long>>C(m,vector<long long>(m));
        for(int i=0;i<m;i++){
            for(int k=0;k<m;k++){
                if(!A[i][k])continue;
                for(int j=0;j<m;j++){
                    C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
                }
            }
        }
        return C;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<vector<long long>>T(m,vector<long long>(m,0));
        for(int j=0;j<m;j++){
            for(int i=m-j;i<m;i++){
                T[i][j]=1;
            }
        }
        auto powT=matPow(T,n-1);
        long long total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                total=(total+powT[i][j])%MOD;
            }
        }
        return (int)(total*2%MOD);
    }
};