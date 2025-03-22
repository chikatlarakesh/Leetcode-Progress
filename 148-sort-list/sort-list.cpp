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
    ListNode* findMiddle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* leftHead,ListNode* rightHead)
    {
        ListNode* dummyNode=new ListNode(-1);
        ListNode* prev=dummyNode;
        ListNode* t1=leftHead;
        ListNode* t2=rightHead;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<t2->val)
            {
                prev->next=t1;
                prev=t1;
                t1=t1->next;
            }
            else
            {
                prev->next=t2;
                prev=t2;
                t2=t2->next;
            }
        }
        if(t1)
        {
            prev->next=t1;
        }
        else
        {
            prev->next=t2;
        }
        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ListNode* middle=findMiddle(head);
        ListNode* leftHead=head;
        ListNode* rightHead=middle->next;
        middle->next=nullptr;
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        return merge(leftHead,rightHead);
    }
};