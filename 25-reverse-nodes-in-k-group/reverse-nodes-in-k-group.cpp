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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> result;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            result.push_back(temp->val);
            temp=temp->next;
        }
        int n=result.size();
        for(int i=0;i+k<=n;i+=k)
        {
            reverse(result.begin()+i,result.begin()+i+k);
        }
        ListNode* prev=new ListNode(result[n-1]);
        prev->next=nullptr;
        for(int i=n-2;i>=0;i--)
        {
            ListNode* newNode=new ListNode(result[i]);
            newNode->next=prev;
            prev=newNode;
        }
        return prev;
    }
};