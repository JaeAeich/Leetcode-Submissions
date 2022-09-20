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
    // //using Hash Map
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*> s;
    //     while(head){
    //         if(find(begin(s),end(s),head)==s.end()){
    //             s.insert(head);
    //             head=head->next;
    //         }
    //         else return head;
    //     }
    //     return NULL;
    // }
    
    // //changing the value of list to an out of bound val.
    // ListNode *detectCycle(ListNode* head){
    //     while(head){
    //         if(head->val==1e6) return head;
    //         head->val=1e6;
    //         head=head->next;
    //     }
    //     return NULL;
    // }
    
    //using hare and tortoise algo
    ListNode *detectCycle(ListNode* head){
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow) break;
        }
        if(!fast or !fast->next) return nullptr;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};


















