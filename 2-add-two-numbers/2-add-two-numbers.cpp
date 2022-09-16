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
    void push_tail(ListNode* &tail,int val){//---> pushes a val to a link list and returns tail.
        if(tail==NULL){
            tail=new ListNode(val);
        }
        ListNode* temp=new ListNode(val);
        tail->next=temp;
        tail=temp;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c=0,sum=0;
        if(l1 && l2) sum=l1->val+l2->val+c;
        else if(l1 && !l2) sum=l1->val+c;
        else if(!l1 && l2) sum=l2->val+c;
        if(l1) l1=l1->next;
        if(l2) l2=l2->next;
        if(sum>9) sum-=10,c=1;
        else c=0;
        ListNode *head=new ListNode(sum),*tail=head;
        while(l1 || l2){
            if(l1 && l2) sum=l1->val+l2->val+c;
            else if(l1 && !l2) sum=l1->val+c;
            else if(!l1 && l2) sum=l2->val+c;
            
            if(sum>9) sum-=10,c=1;
            else c=0;
            push_tail(tail,sum);
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(c) push_tail(tail,c);
        return head;
    }
};










