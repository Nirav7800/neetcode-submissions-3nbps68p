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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* head = new ListNode(-1);
       ListNode* curr = head;
       int c = 0;
       while(l1 && l2) {
           int sum = l1->val+l2->val+c;
           curr->next = new ListNode((sum)%10);
           curr=curr->next;
           c = sum/10;
           l1 = l1->next;
           l2 = l2->next;
       } 

       while(l1) {
           int sum = l1->val+c;
           curr->next = new ListNode((sum)%10);
           curr=curr->next;
           c = sum/10;
           l1 = l1->next;
       }

       while(l2) {
           int sum = l2->val+c;
           curr->next = new ListNode((sum)%10);
           curr=curr->next;
           c = sum/10;
           l2 = l2->next;
       }

       if(c) {
         curr->next = new ListNode(c);
         curr = curr->next;
       }
       return head->next;
    }
};
