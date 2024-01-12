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
    private bool IsSameTree(TreeNode q, TreeNode p){
        if(p == null && q == null) return true;
        
        var isMatch = p?.val == q?.val;
        if(isMatch){
            return IsSameTree(p.left, q.left) && IsSameTree(p.right, q.right);
        }
        else{
            return false;
        }
    }
    public bool IsSubtree(TreeNode root, TreeNode subRoot) {
        if(root == null) return false;
        
        if(IsSameTree(root, subRoot)){
            return true;
        }
        return IsSubtree(root.left, subRoot) || IsSubtree(root.right, subRoot);
    }
}