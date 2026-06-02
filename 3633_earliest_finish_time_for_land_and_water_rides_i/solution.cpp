#include<bits/stdc++.h>
using namespace std;

// Brute Force
// Time Complexity: O(m * n)
// Space Complexity: O(1)
class Solution1 {
    public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            int landFinish=landStartTime[i]+landDuration[i];
            for(int j=0;j<waterStartTime.size();j++){
                int finish=max(landFinish,waterStartTime[j])+waterDuration[j];
                ans=min(ans,finish);
            }
        }
        for(int i=0;i<waterStartTime.size();i++){
            int waterFinish=waterStartTime[i]+waterDuration[i];
            for(int j=0;j<landStartTime.size();j++){
                int finish=max(waterFinish,landStartTime[j])+landDuration[j];
                ans=min(ans,finish);
            }
        }
        return ans;
    }
};



// Optimized
// Time Complexity: O(m + n)
// Space Complexity: O(1)
class Solution2 {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int landFinish=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<landStartTime.size();i++){
            landFinish=min(landFinish,landStartTime[i]+landDuration[i]);
        }
        for( int i=0;i<waterStartTime.size();i++){
            int curr=max(landFinish,waterStartTime[i])+waterDuration[i];
            ans=min(ans,curr);
        }
        int waterFinish=INT_MAX;
        for(int i=0;i<waterStartTime.size();i++){
            waterFinish=min(waterFinish,waterStartTime[i]+waterDuration[i]);
        }
        for( int i=0;i<landStartTime.size();i++){
            int curr=max(waterFinish,landStartTime[i])+landDuration[i];
            ans=min(ans,curr);
        }
        return ans;
    }
};