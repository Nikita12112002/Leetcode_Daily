class LRUCache {
public:
    class Node{
       public: 
        int key,val;
        Node *next,*prev;
        
        Node(int key_ , int val_)
        {
            key=key_;
            val=val_;
        }
    };
    
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int,Node*>m;
    int cap;
    LRUCache(int capacity) {
        
         cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(Node *newnode)
    {
        Node *temp=head->next;
        newnode->next=temp;
        head->next=newnode;
        newnode->prev=head;
        temp->prev=newnode;
    }
     void delnode(Node *delnode)
     {
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
         
     }
    
    int get(int key) {
        
        if(m.find(key)!=m.end())
        {
            Node *res = m[key];
            int ans = res->val;
            m.erase(key);
            delnode(res);
            addnode(res);
            m[key]=head->next;
            return ans;
        }
         return -1;
    }
    
    void put(int key, int value) {
        
        if(m.find(key)!=m.end())
        {
            Node *existing = m[key];
            m.erase(key);
            delnode(existing);
            
        }
        
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        
        Node *nd = new Node(key,value);
        addnode(nd);
        m[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */