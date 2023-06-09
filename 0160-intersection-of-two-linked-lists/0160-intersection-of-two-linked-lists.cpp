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
    // Using Hashing 
//     ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
//         map<ListNode*,int> m;
//         while(l1 and l2){
//             m[l1]++;
//             m[l2]++;
//             if(m[l1]>1) return l1;
//             if(m[l2]>1) return l2;
            
//             l1 = l1 -> next;
//             l2 = l2 -> next;
//         }
//         return nullptr;
//     }
    
    int getLen(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    
    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2)
    {
        // Get the length of both the LL
        int lenA = getLen(l1), lenB = getLen(l2);

        // Find the diff in len, because if they intersect, it will be after that point.
        int diff = abs(lenA - lenB);

        // Move the longer LL
        if (lenA < lenB)
            swap(l1, l2);

        while (diff--)
        {
            l1 = l1->next;
        }

        // Check if they intersect
        while (l1 and l2)
        {
            if (l1 == l2)
                return l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        return nullptr;
    }
};