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
            Node* copyNode=new Node(temp->val);   //First copy nodes create cheyali madhyalo
            copyNode->next=temp->next; //connect chesi copy node ki intermediate ga connections ivali
            temp->next=copyNode;
            temp=temp->next->next;
        }
    
        temp=head;
        while(temp!=NULL)       //copy nodes ki copy node random pointers ni connect cheyali
        {
            if(temp->random!=NULL) temp->next->random=temp->random->next;
            else temp->next->random=nullptr;
            temp=temp->next->next;
        }
        
        temp=head;
        Node* newHead=temp->next;
        while(temp->next->next!=NULL)   //copy nodes ki respective copy nodes next tho connect cheyali
        {
            Node* copyNode=temp->next;
            temp->next=copyNode->next;
            copyNode->next=copyNode->next->next;
            temp=temp->next;
        }
        temp->next=nullptr;
        return newHead;

        // Node* temp=head;             //USING HASHMAP
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