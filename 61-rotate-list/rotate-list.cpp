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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;
        ListNode* temp=head;
        int n=1,count;
        while(temp->next!=NULL)
        {
            n++;
            temp=temp->next;
        }
        k=k%n;
        count=n-k;
        temp->next=head;
        temp=head;
        while(count>1)
        {
            temp=temp->next;
            count--;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};