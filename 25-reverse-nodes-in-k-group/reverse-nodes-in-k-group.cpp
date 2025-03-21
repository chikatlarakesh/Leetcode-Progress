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

    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        ListNode* start=temp;
        ListNode* prev=nullptr;
        while(temp!=NULL)
        {
            count++;
            if(count%k==0)
            {
                ListNode* front=temp->next;
                temp->next=nullptr;
                ListNode* newHead=reverse(start);
                if(head==start)
                {
                    head=temp;
                }
                if(prev)
                {
                    prev->next=temp;
                }
                prev=start;
                temp=front;
                start=front;
            }
            else
            {
                temp=temp->next;
            }
        }
        prev->next=start;
        return head;
    }
};