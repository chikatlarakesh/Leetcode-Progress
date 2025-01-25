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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // if(list1==NULL && list2==NULL)
        // {
        //     return nullptr;
        // }
        // vector<int> result;
        // ListNode* temp=list1;
        // while(temp!=NULL)
        // {
        //     result.push_back(temp->val);
        //     temp=temp->next;
        // }
        // temp=list2;
        // while(temp!=NULL)
        // {
        //     result.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int n=result.size();
        // sort(result.begin(),result.end());
        // ListNode* dummyNode=new ListNode(0);
        // ListNode* newHead=dummyNode;
        // ListNode* val=new ListNode(result[0]);
        // dummyNode->next=val;
        // dummyNode=val;
        // for(int i=1;i<n;i++)
        // {
        //     ListNode* val=new ListNode(result[i]);
        //     dummyNode->next=val;
        //     dummyNode=val;
        // }
        // return newHead->next;

        if(list1==NULL && list2==NULL)
        {
            return nullptr;
        }
        ListNode* t1=list1;
        ListNode* t2=list2;
        ListNode* dummyNode=new ListNode(0);
        ListNode* temp=dummyNode;
        while(t1!=NULL && t2!=NULL)
        {
            if(t1->val<t2->val)
            {
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else
            {
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }
        if(t1!=NULL)
        {
            temp->next=t1;
        }
        if(t2!=NULL)
        {
            temp->next=t2;
        }
        return dummyNode->next;
    }
};