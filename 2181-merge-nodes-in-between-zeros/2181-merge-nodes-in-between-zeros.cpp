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
    vector<int> req(ListNode* head){
        int k=0;
        vector<int> x;
        head=head->next;
        while(head){
            k+=head->val;
            if(head->val==0){
                x.push_back(k);
                k=0;
            }
            head=head->next;
        }
        return x;
    }
    ListNode* mergeNodes(ListNode* head) {
        vector<int> v=req(head);
        // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
        ListNode *nhead=new ListNode(v[0]),*temp=nhead;
        for(int i=1;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }
        
        return nhead;
    }
};