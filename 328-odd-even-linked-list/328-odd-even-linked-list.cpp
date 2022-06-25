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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy_odd=new ListNode(0),*curr_odd=dummy_odd,*dummy_even=new ListNode(0),*curr_even=dummy_even;
        int i=1;
        while(head){
            if(i%2==1){
                curr_odd->next=head;
                curr_odd=curr_odd->next;
            }
            else{
                curr_even->next=head;
                curr_even=curr_even->next;
            }
            i++;
            head=head->next;
        }
        curr_odd->next=dummy_even->next;
        curr_even->next=NULL;
        return dummy_odd->next;
    }
};