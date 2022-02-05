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
        vector<int> v;
        if(lists.size()==0) return NULL;
        for(int i=0;i<lists.size();i++){
            ListNode *xx=lists[i];
            while(xx){
                v.push_back(xx->val);
                xx=xx->next;
            }
        }
        sort(v.begin(),v.end());
        if(v.size()==0)return NULL;
        ListNode *ans=new ListNode(v[0]);
        ListNode *temp=ans;
        for(int i=1;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }
        return ans;
        
    }
};