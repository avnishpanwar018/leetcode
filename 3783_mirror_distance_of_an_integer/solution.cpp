#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int mirrorDistance(int n) {
        int num=n;
        int revNum=0;
        while(num>0){
            revNum=revNum*10+(num%10);
            num/=10;
        }
        return abs(n-revNum);
    }
};