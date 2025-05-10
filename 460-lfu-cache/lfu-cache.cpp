struct Node
{
    int key,value,count;
    Node* prev;
    Node* next;
    Node (int k,int v) : key(k),value(v), count(1), prev(nullptr), next(nullptr) {}
};


class LFUCache {
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

    Node* findLFU()
    {
        Node* temp=head->next;
        int maxCount=INT_MAX;
        Node* lfu;
        while(temp!=tail)
        {
            if(temp->count<=maxCount)
            {
                lfu=temp;
                maxCount=temp->count;
            }
            temp=temp->next;
        }
        return lfu;
    }

public:
    LFUCache(int capacity) {
        limit=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }

    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        Node* temp=m[key];
        temp->count=temp->count+1;
        remove(temp);
        insertAtBegin(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node* temp=m[key];
            temp->value=value;
            temp->count=temp->count+1;
            remove(temp);
            insertAtBegin(temp);
        }
        else
        {
            if(m.size()==limit)
            {
                Node* lfu=findLFU();
                remove(lfu);
                m.erase(lfu->key);
                delete(lfu);
            }
            Node* newNode= new Node(key,value);
            insertAtBegin(newNode);
            m[key]=newNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */