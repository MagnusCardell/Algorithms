// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

public class Solution {
    public int LongestConsecutive(int[] nums) {
        var lookup = new HashSet<int>();
        foreach(var num in nums){
            if(!lookup.Contains(num)){
                lookup.Add(num);
            }
        }
        var maxCount = 0;
        foreach(var num in nums){
            if(!lookup.Contains(num-1)){
               var counter = 1;
                while(lookup.Contains(num+counter)){
                    counter += 1;
                }
                if(maxCount < counter){
                    maxCount = counter;
                }
            }
        }
        return maxCount;
    }
}