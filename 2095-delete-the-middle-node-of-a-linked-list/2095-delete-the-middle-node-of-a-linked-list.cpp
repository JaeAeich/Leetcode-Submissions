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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) return nullptr;
        //we need the a prev pointer of the node to be deleted hence f=f->next->next.
        ListNode* s=head,*f=head->next->next;
        while(f && f->next){
            f=f->next->next;
            s=s->next;
        }
        s->next=s->next->next;
        return head;
    }
};