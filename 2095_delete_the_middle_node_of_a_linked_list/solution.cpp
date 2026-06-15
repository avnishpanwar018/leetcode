#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Length Method
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution1 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)   return nullptr;
        int len=0;
        ListNode*curr=head;
        while(curr){
            curr=curr->next;
            len++;
        }
        curr=head;
        ListNode*temp=nullptr;
        for(int i=0;i<len/2;i++){
            temp=curr;
            curr=curr->next;
        }
        temp->next=curr->next;
        delete curr;
        return head;
    }
};


// Slow/Fast Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution2 {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)    return nullptr;
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};