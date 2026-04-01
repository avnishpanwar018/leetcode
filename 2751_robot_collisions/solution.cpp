#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>indices(n);
        for(int i=0;i<n;i++){
            indices[i]=i;
        }
        sort(indices.begin(),indices.end(),[&](int a,int b){
            return positions[a]<positions[b];
        });
        stack<int>st;
        for(int i:indices){
            if(directions[i]=='R')  st.push(i);
            else{
                while(!st.empty() && healths[i]>0){
                    int j=st.top();
                    if(healths[j]>healths[i]){
                        healths[j]--;
                        healths[i]=0;
                    }
                    else if(healths[j]<healths[i]){
                        healths[j]=0;
                        st.pop();
                        healths[i]--;
                    }
                    else{
                        healths[j]=0;
                        st.pop();
                        healths[i]=0;
                    }
                }
            }
        }
        vector<int>ans;
        for(int x:healths){
            if(x>0) ans.push_back(x);
        }
        return ans;
    }
};