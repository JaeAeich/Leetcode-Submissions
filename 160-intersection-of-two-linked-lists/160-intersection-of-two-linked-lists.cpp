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
    int len(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=len(headA),lenB=len(headB);
        int diff=abs(lenA-lenB);
        //moving the pointer of longer ll , diff ahead beacause thats from where they could be aattached.
        if(lenB>lenA) {
            swap(headA,headB);
        }
        while(diff--){
            headA=headA->next;
        }
        //returning if ptr match else returning null.
        while(headA){
            if(headA==headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return nullptr;
    }
};