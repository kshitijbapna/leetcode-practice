/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL)return 0;
        ListNode *slow=head,*fast=head->next;
        if(!fast)return 0;
        while(slow!=fast&&slow&&fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            // if(slow==fast)return 1;
        }
        if(slow==fast)return 1;
        return 0;
    }
};