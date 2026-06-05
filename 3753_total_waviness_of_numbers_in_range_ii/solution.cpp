#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(d * 10^3)
// Space Complexity: O(d * 10^3)
class Solution {
public:
    vector<long long>dp[20][11][11][2];
    bool vis[20][11][11][2];

    vector<long long>helper(string &s,int idx,bool isBound,int twoBefore,int oneBefore,bool leadingZero){
        if(idx==s.size())   return leadingZero ? vector<long long>{0,0} : vector<long long>{1,0};
        if(!isBound && vis[idx][twoBefore+1][oneBefore+1][leadingZero]) return dp[idx][twoBefore+1][oneBefore+1][leadingZero];
        long long totalCount=0;
        long long totalWaves=0;
        int upper=isBound ? s[idx]-'0' : 9;
        for(int i=0;i<=upper;i++){
            int nextTwoBefore;
            int nextOneBefore;
            long long wave=0;
            bool nextLeadingZero=leadingZero && (i==0);
            if(nextLeadingZero){
                nextTwoBefore=-1;
                nextOneBefore=-1;
            }
            else if(leadingZero){
                nextTwoBefore=-1;
                nextOneBefore=i;
            }
            else{
                nextTwoBefore=oneBefore;
                nextOneBefore=i;
                if(twoBefore!=-1){
                    if((oneBefore>twoBefore && oneBefore>i)||(oneBefore<twoBefore && oneBefore<i))  wave=1;
                }
            }
            bool nextBound=isBound && (i==upper);
            vector<long long>sub=helper(s,idx+1,nextBound,nextTwoBefore,nextOneBefore,nextLeadingZero);
            totalCount+=sub[0];
            totalWaves+=sub[1]+sub[0]*wave;
        }
        vector<long long>ans={totalCount,totalWaves};
        if(!isBound){
            vis[idx][twoBefore+1][oneBefore+1][leadingZero]=true;
            dp[idx][twoBefore+1][oneBefore+1][leadingZero]=ans;
        }
        return ans;
    }

    long long solve(long long n){
        if(n<=0)    return 0;
        string s=to_string(n);
        memset(vis,false,sizeof(vis));
        vector<long long>ans=helper(s,0,true,-1,-1,true);
        return ans[1];
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2)-solve(num1-1);
    }
};