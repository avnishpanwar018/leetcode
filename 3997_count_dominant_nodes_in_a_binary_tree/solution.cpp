#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution {
public:
    int ans=0;

    int dfs(TreeNode*root){
        if(!root)   return 0;
        int leftMax=dfs(root->left);
        int rightMax=dfs(root->right);
        int maxi=max(root->val,max(leftMax,rightMax));
        if(root->val==maxi) ans++;
        return maxi;
    }
    
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};