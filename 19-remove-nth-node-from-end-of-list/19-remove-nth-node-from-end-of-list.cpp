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
    //calculatr len.
    int len(ListNode* head){
        int l=0;
        while(head){
            l++;
            head=head->next;
        }
        return l;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int l=len(head);
        //if first node is to be deleted return the next node pntr.
        if(l==n){
            return head->next;
        }
        //iterate to pointer just before node to be deleted.
        for(int i=1;i<l-n;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};