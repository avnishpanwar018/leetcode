#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O((n + q) log n)
// Space Complexity: O(n log n)
class Solution {
public:
    int n;
    int LOG;
    const long long MOD=1e9+7;
    vector<int>depth;
    unordered_map<int,vector<int>>mpp;
    vector<vector<int>>lift;

    long long power(long long a,long long b){
        long long res=1;
        while(b){
            if(b & 1)   res=res*a%MOD;
            a=a*a%MOD;
            b>>=1;
        }
        return res;
    }

    int lca(int u,int v){
        if(depth[u]<depth[v])   return lca(v,u);
        int diff=depth[u]-depth[v];
        for(int j=0;j<LOG;j++){
            if(diff & (1<<j))   u=lift[u][j];
        }
        if(u==v)    return u;
        for(int j=LOG-1;j>=0;j--){
            if(lift[u][j]!=lift[v][j]){
                u=lift[u][j];
                v=lift[v][j];
            }
        }
        return lift[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n=edges.size()+1;
        depth.assign(n+1,0);
        LOG=1;
        while((1<<LOG)<=n)  LOG++;
        lift.assign(n+1,vector<int>(LOG,0));
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        queue<int>q;
        q.push(1);
        vector<bool>visited(n+1);
        visited[1]=true;
        lift[1][0]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int next:mpp[curr]){
                if(visited[next])   continue;
                depth[next]=depth[curr]+1;
                q.push(next);
                visited[next]=true;
                lift[next][0]=curr;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<LOG;j++){
                lift[i][j]=lift[lift[i][j-1]][j-1];
            }
        }
        vector<int>ans(queries.size());
        for(int i=0;i<queries.size();i++){
            int u=queries[i][0], v=queries[i][1];
            int dist=depth[u]+depth[v]-2*depth[lca(u,v)];
            ans[i]=dist==0 ? 0 : power(2,dist-1);
        }
        return ans;
    }
};