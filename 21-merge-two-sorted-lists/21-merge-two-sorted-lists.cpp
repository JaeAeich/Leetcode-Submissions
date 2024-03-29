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
    // // recursive solution
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    //     if(!l1 && !l2) return NULL;
    //     if(!l1) return l2;
    //     if(!l2) return l1;
    //     if(l1->val<l2->val){
    //         l1->next=mergeTwoLists(l1->next,l2);
    //         return l1;
    //     }
    //     else{
    //         l2->next=mergeTwoLists(l2->next,l1);
    //         return l2;
    //     }
    // }
    
//     //iterative solution
//     ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
//         ListNode *ans,*c,*n;
//         if(!l1){
//             return l2;
//         }
        
//         if(!l2){
//             return l1;
//         }
//         if(!l1 && !l2){
//             return NULL;
//         }
        
//         if(l1->val<l2->val){
//             ans=l1;
//             c=l1;
//             n=l2;
//         }
//         else {
//             ans=l2;
//             c=l2;
//             n=l1;
//         }
//         while(c && n){
//             ListNode* temp=c->next;
            
//             if(!c->next){
//                 c->next=n;
//                 break;
//             }
            
//             if(c->next->val<n->val){
//                 c=c->next;
//             }
//             else{
//                 c->next=n;
//                 n=temp;
//                 c=c->next;
//             }
//         }
//         return ans;
//     }
    //creating a new list
    void pushtail(ListNode* &tail,int data){
        ListNode* temp=new ListNode(data);
        if(tail){
            tail->next=temp;
        }
        tail=temp;
    }
    
    ListNode* mergeTwoLists(ListNode* l1,ListNode* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(!l1 && !l2){
            return NULL;
        }
        ListNode* ans;
        if(l1->val<l2->val){
            ans=new ListNode(l1->val);
            l1=l1->next;
        }
        else{
            ans=new ListNode(l2->val);
            l2=l2->next;
        }
        ListNode* tail=ans;
        while(l1 || l2){
            if(!l1){
                tail->next=l2;
                break;
            }
            if(!l2){
                tail->next=l1;
                break;
            }
            
            if(l1->val>l2->val){
                pushtail(tail,l2->val);
                l2=l2->next;
            }
            else{
                pushtail(tail,l1->val);
                l1=l1->next;
            }
        }
        return ans;
    }
};

































