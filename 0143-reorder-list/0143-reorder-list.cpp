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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;
        int l = 0;
        while(temp){
            s.push(temp);
            temp = temp->next;
            l++;
        }
        ListNode* pptr = head;
        for (int j=0; j<l/2; j++) // Between every two nodes insert the one in the top of the stack
        {
            ListNode *element = s.top();
            s.pop();
            element->next = pptr->next;
            pptr->next = element;
            pptr = pptr->next->next;
        }
        pptr->next = NULL;
    }
};