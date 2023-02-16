public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var numList = nums.ToList();
        numList.Sort();
        
        var result = new List<IList<int>>();
        for(int i = 0; i<numList.Count; ++i){
            if(i > 0 && numList[i] == numList[i-1]){
                continue;
            }
            var left = i + 1;
            var right = numList.Count-1;
            while(left < right){
                var threeSum = numList[i] + numList[left] + numList[right];
                if(threeSum > 0){
                    right -= 1;
                }
                else if(threeSum < 0){
                    left += 1;
                }
                else{
                    result.Add(new List<int>(){numList[i], numList[left], numList[right]});
                    left += 1;
                    while(numList[left] == numList[left-1] && left < right) left += 1;
                }
            }
        }
        
        return result;
    }
}