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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> result;
        for(ListNode* node: lists)
        {
            while(node!=NULL)
            {
                result.push_back(node->val);
                node=node->next;
            }
        }
        int n=result.size();
        sort(result.begin(),result.end());
        ListNode* dummyNode= new ListNode(-1);
        ListNode* temp=dummyNode;
        for(int i=0;i<n;i++)
        {
            ListNode* newNode= new ListNode(result[i]);
            temp->next=newNode;
            temp=newNode;
        }
        temp->next=nullptr;
        return dummyNode->next;
    }
};