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
    ListNode *merge(ListNode* l, ListNode *r){
        ListNode *dum=new ListNode(0),*node;
        node=dum;
        while(l&&r){
            if(l->val<r->val){
                node->next=l;
                l=l->next;
            }
            else{
                node->next=r;
                r=r->next;
            }
            node=node->next;
        }
        if(l)node->next=l;
        if(r)node->next=r;

        return dum->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *fast=head->next->next,*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *r=sortList(slow->next);
        slow->next=NULL;
        ListNode *l=sortList(head);
        return merge(l,r);
    }
};