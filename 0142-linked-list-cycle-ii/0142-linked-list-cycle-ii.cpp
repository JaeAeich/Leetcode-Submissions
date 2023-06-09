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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        // Find the first collision
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast) break;
        }
        
        // If LL got exhausted, no cycle present
        if(!fast or !fast->next) return nullptr;
        
        // Start from the start and move at same rate till collide
        fast = head; 
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        return slow;
        
    }
};