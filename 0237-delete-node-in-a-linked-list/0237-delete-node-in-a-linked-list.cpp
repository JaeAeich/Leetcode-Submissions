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
    // void deleteNode(ListNode* node) {
    //     ListNode** prev =&node;
    //     (*prev)=(*prev)->next->next;
    // }
    void deleteNode(ListNode *node)
    {
        if (node == nullptr || node->next == nullptr)
        {
            // Handle edge cases where the node or next node is null
            return;
        }
        // Copy the next replace this node with next node
        // Delete the next node
        ListNode *nextNode = node->next;
        node->val = nextNode->val;
        node->next = nextNode->next;
        delete nextNode;
    }


};