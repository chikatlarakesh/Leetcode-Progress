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
    // ListNode* merge(ListNode* leftHead,ListNode* rightHead)
    // {
    //     ListNode* dummyNode=new ListNode(-1);
    //     ListNode* prev=dummyNode;
    //     ListNode* t1=leftHead;
    //     ListNode* t2=rightHead;
    //     while(t1!=NULL && t2!=NULL)
    //     {
    //         if(t1->val<t2->val)
    //         {
    //             prev->next=t1;
    //             prev=t1;
    //             t1=t1->next;
    //         }
    //         else
    //         {
    //             prev->next=t2;
    //             prev=t2;
    //             t2=t2->next;
    //         }
    //     }
    //     if(t1)
    //     {
    //         prev->next=t1;
    //     }
    //     else
    //     {
    //         prev->next=t2;
    //     }
    //     return dummyNode->next;
    // }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int n=lists.size();
        // if(n==0) return nullptr;
        // ListNode* t1=lists[0];
        // if(n==1) return t1;
        // for(int i=1;i<n;i++)
        // {
        //     ListNode* t2=lists[i];
        //     t1=merge(t1,t2);
        // }
        // return t1;

        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        int n=lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i])
            {
                pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            if(it.second->next!=NULL)
            {
                pq.push({it.second->next->val,it.second->next});
            }
            temp->next=it.second;
            temp=it.second;
        }
        return dummyNode->next;
    }
};