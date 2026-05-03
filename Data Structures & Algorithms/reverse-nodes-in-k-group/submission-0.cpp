/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check if k nodes exist
        ListNode* curr = head;
        int count = 0;
        while(curr) {
            count++;
            curr=curr->next;
        }

        if(count<k) {
            return head;
        }

        //reverse k nodes
        ListNode* prev = NULL;
        ListNode* nn;
        curr = head;
        count = 0;
        while(curr && count<k) {
            nn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nn;
            count++;
        }

        if(nn) {
            head->next=reverseKGroup(nn,k);
        }
        return prev;
    }
};
