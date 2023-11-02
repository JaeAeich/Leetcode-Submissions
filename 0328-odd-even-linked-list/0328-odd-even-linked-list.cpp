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
        if(!head || !head->next) return head;
        
        ListNode* odd = new ListNode();
        ListNode* ans = odd;
        ListNode* even = new ListNode();
        ListNode* e = even;
        
        bool flag = false;
        
        while(head){
            if(flag){
                even->next = new ListNode(head->val);
                even = even->next;
            }
            else{
                odd->next = new ListNode(head->val);
                odd = odd->next;
            }
            head = head->next;
            flag = !flag;
        }
        odd->next = e->next;
        return ans->next;
    }
};