#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode*slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*prev=nullptr;
        while(slow){
            ListNode*nextNode=slow->next;
            slow->next=prev;
            prev=slow;
            slow=nextNode;
        }
        ListNode*left=head;
        ListNode*right=prev;
        int ans=0;
        while(right){
            ans=max(ans,left->val+right->val);
            left=left->next;
            right=right->next;
        }
        return ans;
    }
};