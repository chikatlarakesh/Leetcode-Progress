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
        if(head==NULL) return head;
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    
        temp=head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL) temp->next->random=temp->random->next;
            else temp->next->random=nullptr;
            temp=temp->next->next;
        }
        
        temp=head;
        Node* newHead=temp->next;
        while(temp->next->next!=NULL)
        {
            Node* copyNode=temp->next;
            temp->next=copyNode->next;
            copyNode->next=copyNode->next->next;
            temp=temp->next;
        }
        temp->next=nullptr;
        return newHead;

        // Node* temp=head;
        // unordered_map<Node*,Node*> mp;
        // while(temp!=NULL)
        // {
        //     Node* copyNode= new Node(temp->val);
        //     mp[temp]=copyNode;
        //     temp=temp->next;
        // }
        // temp=head;
        // while(temp!=NULL)
        // {
        //     Node* copyNode=mp[temp];
        //     copyNode->next=mp[temp->next];
        //     copyNode->random=mp[temp->random];
        //     temp=temp->next;
        // }
        // return mp[head];
    }
};