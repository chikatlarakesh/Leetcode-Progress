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
    int helper(ListNode* temp)
    {
        if(temp==NULL)
        {
            return 0;
        }
        int carry=helper(temp->next);
        int totalSum=(temp->val*2)+carry;
        temp->val=totalSum%10;
        carry=totalSum/10;
        return carry;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry=helper(head);
        if(carry>0)
        {
            ListNode* newNode= new ListNode(carry);
            newNode->next=head;
            return newNode;
        }
        return head;
    }
};