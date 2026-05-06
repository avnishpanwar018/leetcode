#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++){
            int last=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    ans[j][m-i-1]='*';
                    last=j-1;
                }
                else if(boxGrid[i][j]=='#'){
                    ans[last][m-i-1]='#';
                    last--;
                }
            }
        }
        return ans;
    }
};