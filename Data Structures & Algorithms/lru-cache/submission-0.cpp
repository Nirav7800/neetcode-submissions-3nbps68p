struct ListNode{
    int val;
    int key;
    ListNode* prev;
    ListNode* next;
    ListNode() {
        prev=next=NULL;
    }
};

class LRUCache {
private:
    void deleteNode(ListNode* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insertonRight(ListNode* node,ListNode* curr) {
        curr->next->prev=node;
        node->next = curr->next;
        node->prev=curr;
        curr->next = node;
    }
    ListNode* createNode(int key,int value) {
       ListNode* nn = new ListNode();
       nn->key=key;
       nn->val=value;
       return nn;
    }
public:
    unordered_map<int,ListNode*>mp;
    ListNode* head;
    ListNode* tail;
    int size;
    int cap;

    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        head=createNode(-1,-1);
        tail=createNode(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        deleteNode(mp[key]);
        insertonRight(mp[key],head);
        mp[key]=head->next;
        return mp[key]->val;
    }
    
    void put(int key, int value) {

           // if key exists → remove old node
        if(mp.find(key)!=mp.end()) {
            ListNode* curr = mp[key];
            deleteNode(curr);
            delete curr;
            mp.erase(key);
            size--;
        }
        if(size<cap) {
            size++;
            ListNode* nn = createNode(key,value);
            insertonRight(nn,head);
            mp[key]=nn;
        }else {
            ListNode* dn = tail->prev;
            deleteNode(dn);
            mp.erase(dn->key);
            delete dn;
            ListNode* nn = createNode(key,value);
            insertonRight(nn,head);
            mp[key]=nn;
        }
    }
};
