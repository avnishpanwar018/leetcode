#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(Lc + Lq)
// Space Complexity: O(Lc * 26)
// Lc= total length of all container strings
// Lq= total length of all query strings
class Solution {
public:
    struct TrieNode {
        int child[26];
        int idx;

        TrieNode() {
            memset(child,-1,sizeof(child));
            idx=-1;
        }
    };

    vector<TrieNode> trie;

    void update(int &storedIdx,int newIdx,vector<string>& wordsContainer) {
        if(storedIdx==-1) {
            storedIdx=newIdx;
            return;
        }
        int oldLen=wordsContainer[storedIdx].size();
        int newLen=wordsContainer[newIdx].size();
        if(newLen<oldLen) {
            storedIdx=newIdx;
        }
        else if(newLen==oldLen && newIdx<storedIdx) {
            storedIdx=newIdx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.push_back(TrieNode());
        for(int i=0;i<wordsContainer.size();i++) {
            string s=wordsContainer[i];
            reverse(s.begin(),s.end());
            int node=0;
            update(trie[node].idx,i,wordsContainer);
            for(char &ch:s) {
                int c=ch-'a';
                if(trie[node].child[c]==-1) {
                    trie[node].child[c]=trie.size();
                    trie.push_back(TrieNode());
                }
                node=trie[node].child[c];
                update(trie[node].idx,i,wordsContainer);
            }
        }
        vector<int> ans(wordsQuery.size());
        for(int i=0;i<wordsQuery.size();i++) {
            string s=wordsQuery[i];
            reverse(s.begin(),s.end());
            int node=0;
            for(char &ch:s) {
                int c=ch-'a';
                if(trie[node].child[c]==-1) break;
                node=trie[node].child[c];
            }
            ans[i]=trie[node].idx;
        }
        return ans;
    }
};