#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(q log m)
// Space Complexity: O(m)
class SegmentTree{
public:
    int n;
    vector<int>seg;

    SegmentTree(int size){
        n=1;
        while(n<size+1) n<<=1;
        seg.assign(2*n,0);
    }

    void insert(int idx,int val){
        idx+=n;
        seg[idx]=val;
        for(idx>>=1;idx;idx>>=1){
            seg[idx]=max(seg[idx<<1],seg[idx<<1 | 1]);
        }
    }

    int query(int left,int right){
        int ans=0;
        left+=n;
        right+=n;
        while(left<=right){
            if(left & 1)    ans=max(ans,seg[left++]);
            if(!(right & 1))    ans=max(ans,seg[right--]);
            left>>=1;
            right>>=1;
        }
        return ans;
    }
};
    
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int rmax=500001;
        SegmentTree st(rmax);
        set<int>s;
        vector<bool>ans;
        s.insert(0);
        s.insert(rmax);
        st.insert(rmax,rmax);
        for(auto &q:queries){
            if(q[0]==1){
                int x=q[1];
                auto itRight=s.upper_bound(x);
                int right=*itRight;
                auto itLeft=prev(s.lower_bound(x));
                int left=*itLeft;
                s.insert(x);
                st.insert(x,x-left);
                st.insert(right,right-x);
            }
            else{
                int x=q[1];
                int size=q[2];
                int prevPos=*prev(s.upper_bound(x));
                int maxGap=st.query(0,prevPos);
                int mx=max(maxGap,x-prevPos);
                ans.push_back(size<=mx);
            }
        }
        return ans;
    }
};