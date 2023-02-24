/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode ReverseList(ListNode head) {
        if(head == null) return null;
        var previous = new ListNode(head.val, null);
        var next = head.next;
        while(next != null){
            var newNode = new ListNode(next.val, previous);
            previous = newNode;
            next = next.next;
        }
        return previous;
            
    }
}