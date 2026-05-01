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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;
        if(!head || !head->next) return NULL;
        while(fast && count<n) {
            count++;
            fast = fast->next;
        }
        cout<<fast->val<<endl;
        if(!fast->next) return slow->next;
        ListNode* prev = NULL;
        while(fast->next) {
            fast = fast->next;
            prev=slow;
            slow = slow->next;
        }
        prev->next =slow->next;
        return head;
    }
};
