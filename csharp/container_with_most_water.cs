//Two pointer solutino O(n)
public class Solution {
    public int MaxArea(int[] height) {
        
        var maxArea = 0;
        var i = 0;
        var j = height.Length-1;
        while(i<j){
            var area = Math.Min(height[i], height[j]) * (j - i);
            maxArea = Math.Max(area, maxArea);
            
            if(height[i] > height[j]) j -= 1;
            else if(height[j] >= height[i]) i += 1;
        }

        return maxArea;
    }
}

//Brute force O(n2)
public class Solution2 {
    public int MaxArea(int[] height) {
        
        var maxArea = 0;
        for(int i = 0; i<height.Length; ++i){
            for(int j = i+1; j<height.Length; ++j){
                var area = Math.Min(height[i], height[j]) * (j - 1);
                maxArea = Math.Max(area, maxArea);
            }
        }
        return maxArea;
    }
}