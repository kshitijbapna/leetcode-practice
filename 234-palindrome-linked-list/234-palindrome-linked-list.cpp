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
    ListNode *prev=NULL;
    ListNode* mid(ListNode *head){
        ListNode *slow=head,*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    void print(ListNode *head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<"\n";
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)return 1;
        ListNode *mi=mid(head);
        // cout<<prev->val<<" "<<mi->val<<"\n";
        ListNode *pr=NULL,*cur=mi,*ne=NULL;
        while(cur){
            ne=cur->next;
            cur->next=pr;
            pr=cur;
            cur=ne;
        }
        prev->next=pr;
        // print(head);
        ListNode *temp=pr;
        while(temp!=head){
            if(pr->val!=head->val)return 0;
            head=head->next;
            pr=pr->next;
        }
        return 1;
    }
};