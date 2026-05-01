/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr=head;
        if(!head) return head;
        while(curr) {
            Node* nn = curr->next;
            Node* newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next=nn;
            curr=nn;
        }

        curr = head;
        while(curr && curr->next) {
            if(curr->random)
            curr->next->random = curr->random->next;
            curr=curr->next->next;
        }
        curr = head;
        Node* ans = curr->next;
        curr = head;
        Node* ansHead = ans;

        while(curr->next && ans->next) {
            curr->next=curr->next->next;
            ans->next = ans->next->next;
            ans=ans->next;
            curr=curr->next;
        }
        curr->next = NULL;

        return ansHead;
    }
};