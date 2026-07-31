#include<bits/stdc++.h>
using namespace std;

// Simulation (String Padding)
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution1 {
public:
    string pad(int n){
        string s=to_string(n);
        while(s.size()<4){
            s='0'+s;
        }
        return s;
    }

    int generateKey(int num1, int num2, int num3) {
        string s1=pad(num1);
        string s2=pad(num2);
        string s3=pad(num3);
        string key;
        for(int i=0;i<4;i++){
            key.push_back(min({s1[i],s2[i],s3[i]}));
        }
        return stoi(key);
    }
};


// Digit Manipulation
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution2 {
public:
    int generateKey(int num1, int num2, int num3) {
        int place=1;
        int key=0;
        for(int i=0;i<4;i++){
            int d1=num1%10;
            int d2=num2%10;
            int d3=num3%10;
            key+=min({d1,d2,d3})*place;
            num1/=10;
            num2/=10;
            num3/=10;
            place*=10;
        }
        return key;
    }
};