/**
 *  * Definition for binary tree with next pointer.
 *   * public class TreeLinkNode {
 *    *     int val;
 *     *     TreeLinkNode left, right, next;
 *      *     TreeLinkNode(int x) { val = x; }
 *       * }
 *        */
public class Solution {
    public void connect(TreeLinkNode root) {
        if (root == null) return;

        LinkedList<TreeLinkNode> current = new LinkedList<TreeLinkNode>();
        current.add(root);

        while (!current.isEmpty()) {
            int len = current.size();

            for (int i = 0; i < len; i++) {
                TreeLinkNode node = current.removeFirst();

                if (i != len - 1) {
                    node.next = current.peek();
                }
                else {
                    node.next = null;
                }

                if (node.left != null) {
                    current.add(node.left);
                }

                if (node.right != null) {
                    current.add(node.right);
                }
            }
        }
    }
}
