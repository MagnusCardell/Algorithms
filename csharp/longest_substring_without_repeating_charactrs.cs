public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var left = 0;
        var right = 1;
        
        var maxCount = 0;
        var lookup = new HashSet<char>();
        for(int i = 0; i<s.Length; ++i){
            while(lookup.Contains(s[i])){
                lookup.Remove(s[left]);
                left += 1;
            }
            lookup.Add(s[i]);
            if(maxCount < i - left + 1) maxCount = i - left + 1;
            
        }
        return maxCount;
    }
}