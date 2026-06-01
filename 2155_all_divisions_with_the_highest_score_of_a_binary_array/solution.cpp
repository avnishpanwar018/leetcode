#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
    public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int zeros=0,ones=0;
        vector<int>score(n+1);
        score[0]=sum;
        int maxi=sum;
        for(int i=1;i<=n;i++){
            if(nums[i-1]==0)    zeros++;
            else    ones++;
            score[i]=zeros+(sum-ones);
            maxi=max(maxi,score[i]);
        }
        vector<int>ans;
        for(int i=0;i<score.size();i++){
            if(score[i]==maxi)  ans.push_back(i);
        }
        return ans;
    }
};



// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        int score=sum;
        int maxi=score;
        for(int i=0;i<n;i++){
            if(nums[i]==0)  score++;
            else    score--;
            maxi=max(maxi,score);
        }
        vector<int>ans;
        score=sum;
        if(score==maxi) ans.push_back(0);
        for(int i=0;i<n;i++){
            if(nums[i]==0)  score++;
            else    score--;
            if(score==maxi) ans.push_back(i+1);
        }
        return ans;
    }
};