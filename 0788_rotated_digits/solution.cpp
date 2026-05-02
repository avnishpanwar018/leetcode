#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    bool isGood(int n){
        bool isValid=false;
        while(n>0){
            int rem=n%10;
            if(rem==3 || rem==4 || rem==7)  return false;
            else if(rem==2 || rem==5 || rem==6 || rem==9)   isValid=true;
            n/=10;
        }
        return isValid;
    }

    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(isGood(i))   ans++;
        }
        return ans;
    }
};