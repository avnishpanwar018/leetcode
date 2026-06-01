#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(1)
class Solution1 {
    public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i+1<m && grid[i][j]!=grid[i+1][j])   return false;
                if(j+1<n && grid[i][j]==grid[i][j+1])   return false;
            }
        }
        return true;
    }
};



// Time Complexity: O(m * n)
// Space Complexity: O(1)
class Solution2 {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int j=0;j<n;j++){
            for(int i=1;i<m;i++){
                if(grid[i][j]!=grid[0][j])  return false;
            }
        }
        for(int j=0;j<n-1;j++){
            if(grid[0][j]==grid[0][j+1])    return false;
        }
        return true;
    }
};