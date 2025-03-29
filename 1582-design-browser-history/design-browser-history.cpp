class Node
{
public:
    string data;
    Node* next;
    Node* prev;

    Node(): data("0"),next(nullptr),prev(nullptr) {};
    Node(string x): data(x),next(nullptr),prev(nullptr) {};
    Node(string x,Node* next,Node* prev): data(x),next(next),prev(prev) {};
};

class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr= new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=newNode;
    }
    
    string back(int steps) {
        while(steps)
        {
            if(curr->prev)
            {
                curr=curr->prev;
                steps--;
            }
            else break;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps)
        {
            if(curr->next)
            {
                curr=curr->next;
                steps--;
            }
            else break;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */