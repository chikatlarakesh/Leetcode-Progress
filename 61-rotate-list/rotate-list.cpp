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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
        {
            return head;
        }
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        k=k%count;
        if(k==0)
        {
            return head;
        }
        ListNode* newHead=reverse(head);
        temp=newHead;
        while(k>1)
        {
            temp=temp->next;
            k--;
        }
        if(temp!=NULL)
        {
            ListNode* front=temp->next;
            temp->next=nullptr;
            head=reverse(newHead);
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            front=reverse(front);
            temp->next=front;
            return head;
        }
        return newHead;
    }
};