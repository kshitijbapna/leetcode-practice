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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        ListNode *prev,*dummy=new ListNode(0),*nex,*first=dummy,*curr=dummy;
        dummy->next=head;
        // prev=curr;
        while(curr!=NULL&&curr->next!=NULL&&curr->next->next!=NULL){
            prev=curr;
            curr=curr->next;
            nex=curr->next;
            curr->next=nex->next;
            prev->next=nex;
            nex->next=curr;
        }
        return first->next;
    }
};