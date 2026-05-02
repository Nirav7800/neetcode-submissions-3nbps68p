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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=NULL,*curr,*nn;
        curr = head;
        while(curr) {
            nn = curr->next;
            curr->next=prev;
            prev=curr;
            curr=nn;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
                 cout<<"here"<<endl;
        if(!head || !head->next) return;
        ListNode* l1 = head;
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* l2 = slow->next;
        slow->next = NULL;
       
        l2=reverseList(l2);
        
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        cout<<l1->val<<" "<<l2->val<<endl;
        while(l1 || l2) {
            if(l1) {
                curr->next=l1;
                l1=l1->next;
                curr=curr->next;
            }
            if(l2) {
                curr->next=l2;
                l2=l2->next;
                curr=curr->next;
            }
        }
        head=dummyHead->next;
    }
};
