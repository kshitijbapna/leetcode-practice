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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head,*slow=head,*prev=NULL;
        while(n--){
            fast=fast->next;
        }
        while(fast){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev!=NULL&&prev->next!=NULL)
        prev->next=prev->next->next;
        else{
            head=head->next;
        }
        return head;
    }
};