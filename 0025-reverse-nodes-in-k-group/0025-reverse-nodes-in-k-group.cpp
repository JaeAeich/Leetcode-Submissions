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
    // Approach 1 : Recursive
    // Reverse the LL between the ptr s and e
    ListNode* reverse(ListNode* s, ListNode* e){
        ListNode *curr = s, *prev = nullptr;
        
        while(prev!=e){
            ListNode* nextPtr = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextPtr;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If the head or next head is null return head, because its already rev 
        if(!head || !head->next) return head;
        
        // Create start and end pointer of lenght k
        ListNode *s=head, *e = head;
        int c= k-1;
        while(c--){
            e=e->next;
            if(!e) return s;
        }
        
        // Get the of the head of ans after this group
        ListNode *nextHead = reverseKGroup(e->next,k);
        
        // Reverse this group
        reverse(s,e);
        
        // Attach start of this group to the head of the rev LL after this
        s->next = nextHead;
        return e;
    }
};