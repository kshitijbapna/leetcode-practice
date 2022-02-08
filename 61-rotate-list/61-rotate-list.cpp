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
    ListNode *last;
    int len(ListNode* head){
        int l=0;
        while(head){
            l++;
            last=head;
            head=head->next;
        }
        return l;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL)return head;
        int l=len(head);
        k=k%l;
        if(k==0)return head;
        ListNode* temp=head;
        int x=l-k;
        ListNode *prev;
        while(x--){
            prev=head;
            head=head->next;
        }
        prev->next=NULL;
        // cout<<head->val;
        last->next=temp;
        return head;
    }
};