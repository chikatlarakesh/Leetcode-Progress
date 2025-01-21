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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int n = 0;
        ListNode* ele=nullptr;
        while(temp!=NULL)
        {
            n++;
            if(n==k)
            {
                ele=temp;
            }
            temp=temp->next;
        }
        temp=head;
        for(int i=1;i<=n-k;i++)
        {
            temp=temp->next;
        }
        swap(temp->val,ele->val);
        return head;

        // stack<int> st;
        // ListNode* temp=head;
        // int n = 0;
        // temp=head;
        // while(temp!=NULL)
        // {
        //     if(count==k)
        //     {
        //         st.push(temp->val);
        //     }
        //     if(count==n-k+1)
        //     {
        //         st.push(temp->val);
        //     }
        //     count++;
        //     temp=temp->next;
        // }
        // count=1;
        // temp=head;
        // while(temp!=NULL)
        // {
        //     if(count==k)
        //     {
        //         temp->val=st.top();
        //         st.pop();
        //     }
        //     if(count==n-k+1)
        //     {
        //         temp->val=st.top();
        //         st.pop();
        //     }
        //     count++;
        //     temp=temp->next;
        // }
        // return head;
    }
};