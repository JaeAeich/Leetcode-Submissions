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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0;//-->carry 
        ListNode *prevHead=new ListNode(0);
        ListNode *tail=prevHead;
        
        while(c || l1 || l2){
            c+=(l1?l1->val:0)+(l2?l2->val:0);
            tail->next=new ListNode(c%10);//-->since total sum mod 10 is val we need to store.
            tail=tail->next;
            c/=10; // --> carry in decimal sys is numbers right shift 
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        return prevHead->next;
    }
};