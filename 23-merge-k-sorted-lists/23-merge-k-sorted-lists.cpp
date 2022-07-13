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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        for(auto list : lists){
            if(list)
            pq.push({list->val,list});
        }
        ListNode* dummy=new ListNode(-1),*curr=dummy;
        while(!pq.empty()){
            pair<int,ListNode*> x=pq.top();
            pq.pop();
            
            if(x.second->next){
                pq.push({x.second->next->val,x.second->next});
            }
            curr->next=x.second;
            curr=curr->next;
        }
        return dummy->next;
    }
};