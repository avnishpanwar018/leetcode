#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum=0, squareSum=0;
        while(n>0){
            int rem=n%10;
            digitSum+=rem;
            squareSum+=rem*rem;
            n/=10;
        }
        return squareSum-digitSum>=50;
    }
};