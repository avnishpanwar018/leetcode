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
// Space Complexity: O(n)
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mpp;
        unordered_set<int>children;
        for(auto &node:descriptions){
            int parent=node[0], child=node[1], isLeft=node[2];
            if(!mpp.count(parent))  mpp[parent]=new TreeNode(parent);
            if(!mpp.count(child))   mpp[child]=new TreeNode(child);
            if(isLeft)  mpp[parent]->left=mpp[child];
            else    mpp[parent]->right=mpp[child];
            children.insert(child);
        }
        for(auto &node:descriptions){
            int parent=node[0];
            if(!children.count(parent)) return mpp[parent];
        }
        return nullptr;
    }
};