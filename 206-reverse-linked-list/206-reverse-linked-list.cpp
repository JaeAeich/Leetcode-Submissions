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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL,*cur=head;
        while(cur){
            //link prev current node to prev node and move cuurent pointer to the next node.
            ListNode *n=cur->next;
            cur->next=prev;
            prev=cur;
            cur=n;
        }
        return prev;
    }
};