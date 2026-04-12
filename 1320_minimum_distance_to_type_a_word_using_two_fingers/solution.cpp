#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
    vector<vector<vector<int>>>dp;
public:
    int getDist(int ch,int pos){
        if(pos==-1) return 0;
        int x1=ch/6,x2=pos/6;
        int y1=ch%6,y2=pos%6;
        return abs(x1-x2)+abs(y1-y2);
    }
    int helper(string &word,int i,int pos1,int pos2){
        if(i==word.size())  return 0;
        int ch=word[i]-'A';
        if(dp[i][pos1+1][pos2+1]!=-1)   return dp[i][pos1+1][pos2+1];
        int dist1=getDist(ch,pos1)+helper(word,i+1,ch,pos2);
        int dist2=getDist(ch,pos2)+helper(word,i+1,pos1,ch);
        return dp[i][pos1+1][pos2+1]=min(dist1,dist2);
    }
    int minimumDistance(string word) {
        dp.resize(word.size(),vector<vector<int>>(27,vector<int>(27,-1)));
        return helper(word,0,-1,-1);
    }
};