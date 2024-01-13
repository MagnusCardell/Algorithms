public class Solution {
    public int Trap2(int[] height){
        var n = height.Count();
        var maxL = new int[n];
        var max = 0;
        for(int i = 0; i<n; ++i){
            maxL[i] = Math.Max(max, height[i]);
            max = maxL[i];
        }
        var maxR = new int[n];
        max = 0;
        for(int i = n-1; i>=0; --i){
            maxR[i] = Math.Max(max, height[i]);
            max = maxR[i];
        }
        var sum = 0;
        for(int i = 0; i<n; ++i){
            sum += Math.Max(0, Math.Min(maxL[i], maxR[i]) - height[i]);
        }
        return sum;
    }
    public int Trap(int[] height) {
        var n = height.Count();
        var L = 0;
        var R = n-1;
        var maxL = height[L];
        var maxR = height[R];
        var p = 0;
        var sum = 0;
        while(L < R){
            var s = Math.Max(0, Math.Min(maxL, maxR)-height[p]);
            sum += s;
            //Console.WriteLine($"{height[L]} {height[R]} {maxL} {maxR} {p} {s}");
            maxL = Math.Max(maxL, height[L]);
            maxR = Math.Max(maxR, height[R]);
            if(height[L] > height[R]){
                R--;
                p= R;
            }
            else{
                L++;
                p=L;
            }
        }
        return sum;
    }
}
