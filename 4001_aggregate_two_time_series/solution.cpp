#include<bits/stdc++.h>
using namespace std;

// Greedy (Two Pointers)
// Time Complexity: O(m + n)
// Auxiliary Space: O(1)
// Total Space (including output): O(m + n)
class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int m=series1.size();
        int n=series2.size();
        int i=0, j=0;
        vector<vector<int>>ans;
        while(i<m || j<n){
            int t;
            if(j==n || (i<m && series1[i][0]<series2[j][0]))    t=series1[i][0];
            else if(i==m || (j<n && series2[j][0]<series1[i][0]))   t=series2[j][0];
            else    t=series1[i][0];
            int val1 = i<m ? series1[i][1] : 0;
            int val2 = j<n ? series2[j][1] : 0;
            ans.push_back({t,val1+val2});
            if(i<m && series1[i][0]==t)     i++;
            if(j<n && series2[j][0]==t)     j++;
        }
        return ans;
    }
};