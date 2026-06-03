#include<bits/stdc++.h>
using namespace std;

// Frequency Array
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution1 {
public:
    int digitFrequencyScore(int n) {
        string s=to_string(n);
        vector<int>freq(10);
        for(char c:s){
            freq[c-'0']++;
        }
        int score=0;
        for(int i=0;i<freq.size();i++){
            score+=i*freq[i];
        }
        return score;
    }
};



// Digit Extraction
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution2 {
public:
    int digitFrequencyScore(int n) {
        int sum=0;
        while(n>0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
};