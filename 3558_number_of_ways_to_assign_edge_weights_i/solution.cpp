#include<bits/stdc++.h>
using namespace std;

// BFS + Adjacency List + Visited Set
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
    public:
    const long long MOD=1e9+7;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b & 1)   res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mpp;
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        unordered_set<int>vis;
        vis.insert(1);
        int depth=-1;
        while(!q.empty()){
            depth++;
            int size=q.size();
            for(int i=0;i<size;i++){
                int curr=q.front();
                q.pop();
                for(int next:mpp[curr]){
                    if(!vis.count(next)){
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return power(2,depth-1);
    }
};


// Recursive DFS
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
    public:
    int maxDepth=0;
    const long long MOD=1e9+7;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b & 1)   res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }

    void dfs(int u,int parent,int depth,vector<vector<int>>&graph){
        maxDepth=max(maxDepth,depth);
        for(int v:graph[u]){
            if(v!=parent)   dfs(v,u,depth+1,graph);
        }
    }
    
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>graph(n+1);
        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        dfs(1,0,0,graph);
        return power(2,maxDepth-1);
    }
};



// BFS with Parent Tracking
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    const long long MOD=1e9+7;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b & 1)   res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>>graph(n+1);
        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>>q;
        q.push({1,0});
        int depth=-1;
        while(!q.empty()){
            int size=q.size();
            depth++;
            while(size--){
                auto[u,p]=q.front();
                q.pop();
                for(int v:graph[u]){
                    if(v!=p)    q.push({v,u});
                }
            }
        }
        return power(2,depth-1);
    }
};