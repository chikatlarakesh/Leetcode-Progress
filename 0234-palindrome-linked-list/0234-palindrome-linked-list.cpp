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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;
        vector<int> result;
        while(temp)
        {
            result.push_back(temp->val);
            temp=temp->next;
        }
        int n=result.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(result[i]!=result[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};