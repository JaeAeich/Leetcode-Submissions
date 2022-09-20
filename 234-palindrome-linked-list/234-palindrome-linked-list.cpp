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
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        
        ListNode* n=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return n;
    }
    void print(ListNode* h){
        while(h){
            cout<<h->val<<"-->";
            h=h->next;
        }
        cout<<"null"<<endl;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *s=head,*f=head,*temp=head;
        int c=0;
        while(temp){
            c++;
            temp=temp->next;
        }
        while(f && f->next){
            s=s->next;
            f=f->next->next;
        }
        if(c&1)s=s->next;
        ListNode* rev=reverse(s);
        while(rev){
            if(rev->val!=head->val) return false;
            rev=rev->next;
            head=head->next;
        }
        return true;
    }
};