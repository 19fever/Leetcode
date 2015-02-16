/**
 *  * Definition for binary tree
 *   * public class TreeNode {
 *    *     int val;
 *     *     TreeNode left;
 *      *     TreeNode right;
 *       *     TreeNode(int x) { val = x; }
 *        * }
 *         */
public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
        return helper(num, 0, num.length - 1);
    }

    public TreeNode helper(int[] num, int left, int right) {
        if (left > right) 
            return null;
        int mid = (left + right) / 2;
        TreeNode node = new TreeNode(num[mid]);
        node.left = helper(num, left, mid - 1);
        node.right = helper(num, mid + 1, right);
        return node;
    }
}
