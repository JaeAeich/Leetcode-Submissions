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
        ListNode* ans=new ListNode(0),*dummy=ans;
        int c=0; // -->carry from the sum.
        while(l1 || l2){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+c;
            if(sum>9){
                c=1;
                sum=sum-10;
            }
            else c=0;
            ListNode* temp=new ListNode(sum);
            dummy->next=temp;
            dummy=temp;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(c) dummy->next=new ListNode(c);
        return ans->next;
    }
};