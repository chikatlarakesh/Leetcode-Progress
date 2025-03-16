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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> m;
        for(int num:nums)
        {
            m[num]++;
        }
        ListNode* temp=head;
        ListNode* prev=new ListNode(-1);
        ListNode* newHead=prev;
        while(temp!=NULL)
        {
            if(m.find(temp->val)==m.end())
            {
                prev->next=temp;
                prev=temp;
            }
            temp=temp->next;
        }
        prev->next=nullptr;
        return newHead->next;
    }
};