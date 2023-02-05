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
    // // using hash table
    // bool hasCycle(ListNode *head) {
    //     unordered_map<ListNode*,int> m;
    //     int i=0;
    //     while(head){
    //         if(m.find(head)==m.end()){
    //             m[head]=i;
    //             i++;
    //             head=head->next;
    //         }
    //         else return true;
    //     }
    //     return false;
    // }
    
    // // using flag
    // bool hasCycle(ListNode* head){
    //     while(head){
    //         if(head->val==1e6) return true;
    //         else head->val=1e6,head=head->next;
    //     }
    //     return false;
    // }
    
    //Floyd's cycle finding algorithm
    bool hasCycle(ListNode* head){
        if(head==NULL || head->next==NULL) return false;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};











