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
private:
    int len(ListNode* head){
        int c=0;
        while(head){
            c++;
            head=head->next;
        }
        return c;
    }
    
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //if zero rots then return the same list.
        if(k==0 || !head) return head;
        ListNode* temp=head;
        int l=len(head);
        //if num of rots greater that len then rots is k%l.
        k%=l;
        //making it a circular ll.
        while(temp->next) temp=temp->next;
        temp->next=head;
        temp=temp->next;
        //disjoining the link where the rotated ll has to end. 
        for(int i=0;i<l-k-1;++i){
            temp=temp->next;
        }
        ListNode* ans=temp->next;
        temp->next=nullptr;
        return ans;
    }
};

















