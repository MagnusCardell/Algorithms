/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    private int FindDepth(TreeNode node, int currentDepth){
        if(node == null){
            return currentDepth;
        }
        
        var leftDepth = FindDepth(node.left, currentDepth + 1);
        var rightDepth = FindDepth(node.right, currentDepth + 1);
        return leftDepth > rightDepth ? leftDepth : rightDepth;
    }
    
    public int MaxDepth(TreeNode root) {
        var depth = FindDepth(root, 0);
        return depth;
    }
}