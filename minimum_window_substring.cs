// Minimum window substring
// Given input s and t, return the size of the minimum window where all characters in t is in s
// Example: s = GABCDEFG, t = EG, minimum window = EFG, size = 3

public class Solution{
    // sliding window solution
    // right, left at 0.
    // create key Hash of s [1,1,1,1,1,1,2,0,0,0,....']
    // every iteration - increase right
    // check for valid window
    // if yes, compare size - save smallest size
    public int MinimumWindowSubstring(string s, string t){ // ADABCD, CD
        // assign return value
        var minWindowSize = 0;

        // construct lookup key for t
        var tKey = new int[26]; //[1,1,1,2,0,0,0,...]
        foreach( var x in t){
            tKey[(int)x - 96] += 1;
        }
        
        // assign sliding window boundaries
        var left = 0; 
        var right = 0; 
        
        // assign lookup key for sliding window
        var xKey = new int[26]; 
        
        // start iterating
        while(right < s.Length){ 

            // update sliding window lookup
            xKey[(int)s[right]-96] += 1;

            var isSubstring = false;
            // check for valid window
            var isValid = true;
            for(int i = 0; i<26; ++i){
                if(s[i] >= t[i]){
                    isValid = false;
                    break;
                } 
                else {
                    isSubstring = true;
                }
            }
            // if valid, save it if smallest size
            if(isValid){
                var currentSize = right - left + 1;
                minWindowSize = Math.Minimum(minWindowSize, currentSize);
            }

            // if partial substring is found, keep left still
            if(!isSubstring){
                left += 1;
            }

            // if any minWindow has been found, increase left pointer since we only want smaller windows
            if(minWindowSize > 0){
                left += 1;
            }
            right += 1;

        }

        return minWindowSize;
    }
}


public class Solution {
    // Sliding window approach
    // Starting at 0, incrase window until valid window is found
    // Valid window = t is a subset of s
    public string MinWindow(string s, string t) {
        if(t.Length > s.Length) return "";

        var left = 0;
        var right = 0;

        var tLookup = new Dictionary<char, int>();
        foreach(var c in t){
            // Increment character count
            tLookup.TryGetValue(c, out var cunt);
            tLookup[c] = count + 1;
        }

        var window = new Dictionary<char, int>();
        var have = 0;
        var need = t.Length;
        for(right = 0; right < s.Length; ++right){

            
            if(tMap.ContainsKey(s[right])){

                // if exists in t, update window and check validity
                window.TryGetValue(s[right], out var count);
                window[s[right]] = count + 1;
                have += 1;

                if(have >= need){
                    foreach(var key in tLookup.GetKeys()){
                        if(tLookup[key] <= window[key]){

                        }
                    }
                }
            }
            
        }
    }
}