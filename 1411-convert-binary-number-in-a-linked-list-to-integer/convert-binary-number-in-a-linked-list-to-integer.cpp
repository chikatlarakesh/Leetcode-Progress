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

    int getDecimalValue(ListNode* head) {
        ListNode* newHead= reverse(head);

        int power=1,result=0;
        ListNode* temp=newHead;
        while(temp)
        {
            result+=(temp->val)*power;
            power*=2;
            temp=temp->next;
        }
        return result;
    }
};