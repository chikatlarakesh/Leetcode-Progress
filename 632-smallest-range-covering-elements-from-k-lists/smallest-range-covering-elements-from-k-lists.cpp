class Node{
    public:
    int data;
    int row;
    int col;

    Node(int data1,int row1,int col1)
    {
        data=data1;
        row=row1;
        col=col1;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b)
    {
        return a->data>b->data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*,vector<Node*>,compare> pq;
        int k=nums.size();
        int i,n;
        int mini=INT_MAX,maxi=INT_MIN;
        for(i=0;i<k;i++)
        {
            int val=nums[i][0];
            mini=min(mini,val);
            maxi=max(maxi,val);
            pq.push(new Node(val,i,0));
        }
        int start=mini,end=maxi;
        while(!pq.empty())
        {
            Node* temp=pq.top();
            pq.pop();

            mini=temp->data;
            if(maxi-mini<end-start)
            {
                start=mini;
                end=maxi;
            }
            int currListLen=nums[temp->row].size();
            if(temp->col+1<currListLen)
            {
                int val=nums[temp->row][temp->col+1];
                maxi=max(maxi,val);
                pq.push(new Node(val,temp->row,temp->col+1));
            }
            else break;
        }
        return {start,end};
    }
};