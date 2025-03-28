/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* t1=headA;
        ListNode* t2=headB;
        int n1=0,n2=0;
        while(t1!=NULL)
        {
            n1++;
            t1=t1->next;
        }
        while(t2!=NULL)
        {
            n2++;
            t2=t2->next;
        }
        t1=headA;
        t2=headB;
        int d=abs(n1-n2);
        if(n2>n1)
        {
            while(d>0)
            {
                t2=t2->next;
                d--;
            }
        }
        else
        {
            while(d>0)
            {
                t1=t1->next;
                d--;
            }
        }
        while(t1!=t2 && t1!=NULL && t2!=NULL)
        {
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }
};