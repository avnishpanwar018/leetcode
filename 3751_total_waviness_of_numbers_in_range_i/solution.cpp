#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((num2-num1) * log num2)
// Space Complexity: O(log num2)
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peak=0, valley=0;
        for(int i=num1;i<=num2;i++){
            string s=to_string(i);
            for(int j=1;j<s.size()-1;j++){
                if(s[j-1]<s[j] && s[j]>s[j+1])  peak++;
                else if(s[j-1]>s[j] && s[j]<s[j+1]) valley++;
            }
        }
        return peak+valley;
    }
};