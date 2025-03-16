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
        unordered_set<int> s;
        for(int num:nums)
        {
            s.insert(num);
        }
        vector<int> result;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            result.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* prev=new ListNode(-1);
        ListNode* newHead=prev;
        for(int num:result)
        {
            if(s.find(num)==s.end())
            {
                ListNode* newNode= new ListNode(num);
                prev->next=newNode;
                prev=newNode;
            }
        }
        prev->next=nullptr;
        return newHead->next;
    }
};