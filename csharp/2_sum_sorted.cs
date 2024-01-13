public class Solution {
    public int[] TwoSum(int[] numbers, int target){
        var l = 0;
        var r = numbers.Count()-1;

        while(l < r){
            var sum = numbers[l] + numbers[r];
            if(sum == target){
                return new int[2]{l+1, r+1};
            }
            if(sum > target){
                r--;
            }
            else{
                l++;
            }
        }
        return new int[0];
    }

    public int[] TwoSum2(int[] numbers, int target) {
        var n = numbers.Count();
        var lookup = new Dictionary<int, int>();
        for(int i = 0; i<n; ++i){
            var c = target - numbers[i];
            if(lookup.ContainsKey(c)){
                return new int[2]{lookup[c], i+1};
            }
            else{
                lookup[numbers[i]] = i+1;
            }
        }
        return new int[0];
    }
}
