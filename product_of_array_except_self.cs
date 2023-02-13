// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

public class Solution {
    //iterate from left, then right so time complexity O(n) and memory: o(n)
    public int[] ProductExceptSelf(int[] nums) {
        var result = new int[nums.Count()];
        var prefix = 1;
        for(int i = 0; i<nums.Count(); ++i){
            result[i] = prefix;
            prefix *= nums[i];
        }
        prefix = 1;
        for(int i = nums.Count()-1; i>=0; --i){
            result[i] *= prefix;
            prefix *= nums[i];
        }
        return result;
    }
}