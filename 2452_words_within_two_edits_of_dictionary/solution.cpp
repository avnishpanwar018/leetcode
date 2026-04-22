#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(q * d * l)
// Space Complexity: O(1)
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(auto &q:queries){
            for(auto &d:dictionary){
                if(q.size()!=d.size())  continue;
                int diff=0;
                for(int k=0;k<q.size() && diff<=2;k++){
                    if(q[k]!=d[k])  diff++;
                }
                if(diff<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};