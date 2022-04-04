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
static bool     _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
class Solution {
public:
    ListNode* l22=NULL;
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l1=head,*l2=head;
        int y=k-1;
        while(y--){
            l2=l2->next;
        }
        l22=l2;
        while(l2->next){
            l2=l2->next;
            l1=l1->next;
        }
        swap(l1->val,l22->val);
        return head;
    }
};
