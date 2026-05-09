#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m + n)
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int r1=0,r2=m-1;
        int c1=0,c2=n-1;
        while(r1<r2 && c1<c2){
            vector<int>temp;
            for(int j=c1;j<c2;j++){
                temp.push_back(grid[r1][j]);
            }
            for(int i=r1;i<r2;i++){
                temp.push_back(grid[i][c2]);
            }
            for(int j=c2;j>c1;j--){
                temp.push_back(grid[r2][j]);
            }
            for(int i=r2;i>r1;i--){
                temp.push_back(grid[i][c1]);
            }
            int shift=k%temp.size();
            reverse(temp.begin(),temp.begin()+shift);
            reverse(temp.begin()+shift,temp.end());
            reverse(temp.begin(),temp.end());
            int idx=0;
            for(int j=c1;j<c2;j++){
                grid[r1][j]=temp[idx++];
            }
            for(int i=r1;i<r2;i++){
                grid[i][c2]=temp[idx++];
            }
            for(int j=c2;j>c1;j--){
                grid[r2][j]=temp[idx++];
            }
            for(int i=r2;i>r1;i--){
                grid[i][c1]=temp[idx++];
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return grid;
    }
};