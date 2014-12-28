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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        int lenA = 0;
        int lenB = 0;
        
        while (pA != NULL) {
            lenA++;
            pA = pA->next;
        }
        
        while (pB != NULL) {
            lenB++;
            pB = pB->next;
        }
        
        if (lenA > lenB) {
            while (lenA > lenB) {
                headA = headA->next;
                lenA--;
            }
        }
        else {
            while (lenB > lenA) {
                headB = headB->next;
                lenB--;
            }
        }
        
        while (headA != NULL && headB != NULL) {
            if (headA->val == headB->val) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};
