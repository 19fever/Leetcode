/**
 *  * Definition for singly-linked list.
 *   * public class ListNode {
 *    *     int val;
 *     *     ListNode next;
 *      *     ListNode(int x) {
 *       *         val = x;
 *        *         next = null;
 *         *     }
 *          * }
 *           */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null) return head; 
        ListNode dummy = new ListNode(-1);
        ListNode cur = head;

        while (cur != null) {
            ListNode p = dummy;
            while (p.next != null && cur.val > p.next.val) {
                p = p.next;
            }
            ListNode next = cur.next;
            cur.next = p.next;
            p.next = cur;
            cur = next;
        }

        return dummy.next;
    }
}
