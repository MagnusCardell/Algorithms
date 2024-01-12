/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution2 {
    public bool HasCycle(ListNode head) {
        var lookup = new Dictionary<ListNode, bool>();
        while(head != null){
            if(lookup.ContainsKey(head)) return true;
            lookup[head] = true;
            head = head.next;
        }
        return false;
    }
}

//Floyds tortoise and hare algo -- space O(1)
public class Solution{
    public bool HasCycle(ListNode head){
        
        var hare = head?.next?.next;
        var tort = head?.next;
        
        while(hare != null && tort != null){
            if(hare == tort) return true;
            hare = hare?.next?.next;
            tort = tort?.next;
        }
        return false;
    }
}