#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int secondHighest(string s) {
        int largest=-1, secondLargest=-1;
        for(char c:s){
            if(!isdigit(c)) continue;
            int d=c-'0';
            if(d>largest){
                secondLargest=largest;
                largest=d;
            }
            else if(d<largest && d>secondLargest)    secondLargest=d;
        }
        return secondLargest;
    }
};