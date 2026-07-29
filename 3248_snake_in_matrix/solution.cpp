#include<bits/stdc++.h>
using namespace std;

// Simulation
// Time Complexity: O(m), where m=commands.size()
// Space Complexity: O(1)
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i=0, j=0;
        for(string s:commands){
            if(s=="UP") i--;
            else if(s=="RIGHT") j++;
            else if(s=="DOWN")  i++;
            else    j--;
        }
        return (i*n)+j;
    }
};