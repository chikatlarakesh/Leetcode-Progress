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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> result;
        ListNode* newHead=reverseLL(head);
        stack<ListNode*> st;
        ListNode* temp=newHead;
        while(temp!=NULL)
        {
            if(st.empty())
            {
                result.push_back(0);
            }
            else if(st.top()->val>temp->val)
            {
                result.push_back(st.top()->val);
            }
            else
            {
                while(!st.empty() && st.top()->val<=temp->val)
                {
                    st.pop();
                }
                if(st.empty()) result.push_back(0);
                else result.push_back(st.top()->val);
            }
            st.push(temp);
            temp=temp->next;
        }
        reverse(result.begin(),result.end());
        head=reverseLL(newHead);
        return result;
    }
};