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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>> >minH;
        for(auto i:lists) {
            if(i==NULL) continue;
            minH.push({i->val,i});
        }
        ListNode* head=new ListNode(-1);
        ListNode* curr=head;
        while(!minH.empty()) {
            auto top = minH.top();
            minH.pop();
            ListNode* node = top.second;
            curr->next = node;
            curr=curr->next;
            if(node->next) {
                minH.push({node->next->val,node->next});
            }
            
        }
        return head->next;
    }
};
