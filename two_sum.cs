// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

class Solution {
    // space complexity O(n)
    // memory O(n)
    public int[] TwoSum(int[] nums, int target) {
        var remainderLookup = new Dictionary<int, int>();
        for(int i = 0; i<nums.Length; ++i) {
            var n = nums[i];
            var targetN = target - n;
            if(remainderLookup.ContainsKey(targetN)) return new int[]{remainderLookup[targetN], i};
            else{
                remainderLookup[n] = i;
            }
        }
        return null;
    }
}