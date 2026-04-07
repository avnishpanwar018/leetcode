#include<bits/stdc++.h>
using namespace std;

class Robot {
public:
    vector<vector<int>>cells;
    int count=0;

    // TC=O(width + height)     SC=O(width + height)
    Robot(int width, int height) {
        // 0=E 1=N 2=W 3=S
        cells.push_back({0,0,3});

        for(int i=1;i<width;i++){
            cells.push_back({i,0,0});
        }
        for(int j=1;j<height;j++){
            cells.push_back({width-1,j,1});
        }
        for(int i=width-2;i>=0;i--){
            cells.push_back({i,height-1,2});
        }
        for(int j=height-2;j>0;j--){
            cells.push_back({0,j,3});
        }
    }
    
    // TC=O(1)      SC=O(1)
    void step(int num) {
        count+=num;        
    }
    
    // TC=O(1)      SC=O(1)
    vector<int> getPos() {
        int idx=count%cells.size();
        int x=cells[idx][0];
        int y=cells[idx][1];
        return {x,y};
    }
    
    // TC=O(1)      SC=O(1)
    string getDir() {
        if(count==0)    return "East";
        int idx=count%cells.size();
        int dir=cells[idx][2];
        if(dir==0)  return "East";
        else if(dir==1) return "North";
        else if(dir==2) return "West";
        else    return "South";
    }
};