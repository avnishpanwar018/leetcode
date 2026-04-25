#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n * log n + n * k * log n * log side)​
// Space Complexity: O(n)
class Solution {
public:
    int lower(vector<long long>&v,long long target){
        int low=0,high=v.size();
        while(low<high){
            int mid=low+(high-low)/2;
            if(v[mid]<target)   low=mid+1;
            else    high=mid;
        }
        return low;
    }

    bool isValid(vector<long long>&v,int side,int k,long long dist){
        long long peri=4LL*side;
        for(int i=0;i<v.size();i++){
            long long start=v[i];
            long long end=start+peri-dist;
            for(int j=0;j<k-1;j++){
                int next=lower(v,start+dist);
                if(next>=v.size() || v[next]>end){
                    start=-1;
                    break;
                }
                start=v[next];
            }
            if(start>=0)    return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long>v;
        for(auto &p:points){
            long long x=p[0],y=p[1];
            if(x==0)    v.push_back(y);
            else if(y==side)    v.push_back(side+x);
            else if(x==side)    v.push_back(2LL*side+(side-y));
            else    v.push_back(3LL*side+(side-x));
        }
        sort(v.begin(),v.end());
        int ans=0;
        long long low=1,high=2LL*side;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(isValid(v,side,k,mid)){
                low=mid+1;
                ans=mid;
            }
            else    high=mid-1;
        }
        return ans;
    }
};