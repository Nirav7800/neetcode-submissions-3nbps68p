/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, unordered_map<int,Node*>&mp,unordered_set<int>&vis) {
        if(!node) return;
        if(vis.find(node->val)!=vis.end()) return;
        vis.insert(node->val);
        for(auto v:node->neighbors){
            if(!mp.count(v->val)) mp[v->val]=new Node(v->val);
            mp[node->val]->neighbors.push_back(mp[v->val]);
            dfs(v,mp,vis);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<int,Node*>mp;
        mp[node->val]=new Node(node->val);
        unordered_set<int>vis;
        dfs(node,mp,vis);
        return mp[1];
    }
};
