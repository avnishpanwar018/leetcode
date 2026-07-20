#include<bits/stdc++.h>
using namespace std;

// Brute Force Simulation
// Time Complexity: O(k * m * n)
// Space Complexity: O(1)
class Solution1 {
    public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        while(k--){
            int prev=grid[m-1][n-1];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    int temp=grid[i][j];
                    grid[i][j]=prev;
                    prev=temp;
                }
            }
        }
        return grid;
    }
};


// Index Mapping
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution2 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int total=m*n;
        k%=total;
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int oldIndex=i*n+j;
                int newIndex=(oldIndex+k)%total;
                int newRow=newIndex/n;
                int newCol=newIndex%n;
                ans[newRow][newCol]=grid[i][j];
            }
        }
        return ans;
    }
};