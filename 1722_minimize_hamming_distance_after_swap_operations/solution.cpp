#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((n + m ) * α(n))  where α(n) is the inverse Ackermann function
// Space Complexity: O(n)
class Solution {
public:
    vector<int>rank;
    vector<int>parent;

    int find(int x){
        if(parent[x]!=x)    parent[x]=find(parent[x]);
        return parent[x];
    }

    void Union(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX==rootY)    return;
        if(rank[rootX]<rank[rootY]) swap(rootX,rootY);
        parent[rootY]=rootX;
        if(rank[rootX]==rank[rootY])    rank[rootX]++;
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        rank.resize(n,0);
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto &it:allowedSwaps){
            Union(it[0],it[1]);
        }
        unordered_map<int,unordered_map<int,int>>mpp;
        for(int i=0;i<n;i++){
            int parent=find(i);
            mpp[parent][source[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int parent=find(i);
            if(mpp[parent][target[i]]>0)    mpp[parent][target[i]]--;
            else    ans++;
        }
        return ans;
    }
};