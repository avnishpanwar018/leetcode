#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols=encodedText.size()/rows;
        vector<vector<char>>mat(rows,vector<char>(cols));
        int i=0,j=0;
        for(int idx=0;idx<encodedText.size();idx++){
            mat[i][j]=encodedText[idx];
            if(j<cols-1)    j++;
            else{
                i++;
                j=0;
            }
        }
        string ans="";
        for(j=0;j<cols;j++){
            for(i=0;i<rows;i++){
                if(j+i<cols)    ans+=mat[i][j+i];
            }
        }
        while(!ans.empty() && ans.back()==' '){
            ans.pop_back();
        }
        return ans;
    }
};