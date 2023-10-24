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
        priority_queue<int,vector<int>, greater<int>> q;
        for(auto l:lists){
            while(l){
                q.push(l->val);
                l=l->next;
            }
        }
        ListNode* finans = new ListNode();
        ListNode *ans = finans;
        while(!q.empty()){
            int val = q.top();
            q.pop();
            ans->next = new ListNode(val);
            ans=ans->next;
        }
        return finans->next;
    }
};