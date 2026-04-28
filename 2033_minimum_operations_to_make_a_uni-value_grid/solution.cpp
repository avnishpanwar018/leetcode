#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n * log(m * n))
// Space Complexity: O(m * n)
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int rem=grid[0][0]%x;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]%x!=rem)   return -1;
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        long long ans=0;
        int mid=arr.size()/2;
        for(int val:arr){
            ans+=abs((long long)arr[mid]-val)/x;
        }
        return ans;
    }
};