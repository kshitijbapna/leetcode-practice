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
    int len(ListNode* head){
        int cnt=0;
        while(head){
            cnt++;
            head=head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(len(head)<k)return head;
        if(head==NULL)return head;
        ListNode *curr=head,*nex=head->next,*prev=NULL;
        int kk=k;
        while(curr&&kk--){
            curr->next=prev;
            prev=curr;
            curr=nex;
            if(nex)
            nex=nex->next;
        }
        if(curr!=NULL)
        head->next=reverseKGroup(curr,k);
        // if(prev)cout<<prev->val<<" ";
        return prev;
    }
};