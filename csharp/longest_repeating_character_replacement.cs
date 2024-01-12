public class Solution {
    // Sliding window and remembering the size of greatest window so far
    // Time complexity: O(n)
    // Memory: O(n)
    public int CharacterReplacement(string s, int k) {
        var maxCount = 0;
        var left = 0; 
        var right = 0; 
        
        var alphabetLookup = new int[26]; 
        var mostFrequent = 0;
        for(right = 0; right<s.Length; ++right){
            alphabetLookup[(int)s[right]-65] += 1; 

            // Save the most frequent character            
            mostFrequent = Math.Max(mostFrequent, alphabetLookup[(int)s[right]-65]);

            // Caluclate if valid window
            var isValidWindow = ((right+1 - left) - mostFrequent) <= k;
            if(!isValidWindow){
                // If not, move left pointer up (keep window size the same)
                alphabetLookup[(int)s[left]-65] -= 1;
                left += 1;
            }
            maxCount = Math.Max(maxCount, (right+1 - left));
        }
        return maxCount;
    }

    // Sliding window
    // maintain left & pointers, each iteration check or valid window. If not increase left, else increase right.
    // Time complexity: O(26n) => O(n)
    // Memory: O(n)
    public int CharacterReplacement2(string s, int k) {
        var maxCount = 0;
        var left = 0;
        var right = 0;
        
        var alphabetLookup = new int[26];
        for(right = 0; right<s.Length; ++right){
            alphabetLookup[(int)s[right]-65] += 1; 

            var mostFrequentCount = 0;
            for(int i = 0; i<26; ++i){
                mostFrequentCount = Math.Max(mostFrequentCount, alphabetLookup[i]);
            }

            var isValidWindow = ((right+1 - left) - mostFrequentCount) <= k;
            if(!isValidWindow){
                while(!isValidWindow && left <= right){
                    alphabetLookup[(int)s[left]-65] -= 1;
                    left += 1;

                    mostFrequentCount = 0;
                    for(int i = 0; i<26; ++i){
                        mostFrequentCount = Math.Max(mostFrequentCount, alphabetLookup[i]);
                    }
                    isValidWindow = ((right+1 - left) - mostFrequentCount) <= k;
                }
            }
            maxCount = Math.Max(maxCount, (right+1 - left));
        }
        return maxCount;
    }
}