public class Solution {
    // O(n) solution with O(n) memory
    public bool ContainsDuplicate(int[] nums) {
        var lookup = new HashSet<int>();
        foreach(var num in nums){
            if(lookup.Contains(num)) return true;
            lookup.Add(num);
        }
        return false;
    }
}