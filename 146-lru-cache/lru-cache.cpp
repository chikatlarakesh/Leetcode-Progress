struct Node
{
    int key,value;
    Node* prev;
    Node* next;

    Node (int k,int v) : key(k),value(v), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    int limit=0;
    unordered_map<int,Node*> m;
    Node* head;
    Node* tail;

    void insertAtBegin(Node* node)
    {
        node->next=head->next;
        node->next->prev=node;
        node->prev=head;
        head->next=node;
    }

    void remove(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

public:
    LRUCache(int capacity) {
        limit=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* temp=m[key];
        remove(temp);
        insertAtBegin(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node* temp=m[key];
            temp->value=value;
            remove(temp);
            insertAtBegin(temp);
        }
        else
        {
            if(m.size()==limit)
            {
                Node* lru=tail->prev;
                remove(lru);
                m.erase(lru->key);
                delete(lru);
            }
            Node* newNode= new Node(key,value);
            insertAtBegin(newNode);
            m[key]=newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */