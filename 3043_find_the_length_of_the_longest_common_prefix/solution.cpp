#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((n + m) * d)
// Space Complexity: O(n * d)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int>st;
        for(int i=0;i<arr1.size();i++){
            int k=arr1[i];
            while(k){
                st.insert(k);
                k/=10;
            }
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            int k=arr2[i];
            while(k){
                if(st.count(k)){
                    int len=to_string(k).size();
                    ans=max(ans,len);
                    break;
                }
                k/=10;
            }
        }
        return ans;
    }
};