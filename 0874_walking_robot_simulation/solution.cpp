#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(m log m + k log m)
// where m=obstacles.size(),k=total steps taken
// Space Complexity: O(m)
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>>s;
        for(auto it:obstacles){
            s.insert({it[0],it[1]});
        }
        int x=0,y=0;
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        int position=0; // 0=N 1=E 2=S 3=W
        int ans=0;
        for(int c:commands){
            if(c==-1)   position=(position+1)%4;
            else if(c==-2)  position=(position+3)%4;
            else{
                for(int i=0;i<c;i++){
                    if(s.count({x+dir[position][0],y+dir[position][1]}))    break;
                    else{
                        x+=dir[position][0];
                        y+=dir[position][1];
                    }
                }
                ans=max(ans,x*x+y*y);
            }
        }
        return ans;
    }
};