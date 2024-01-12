public class Solution {

    // Time complexity O(s + t)
    // Memory O(s + t)
    public bool IsAnagram(string s, string t) {
        if(s.Length != t.Length) return false;
        var sourceLookup = new Dictionary<char, int>();
        foreach(var char_s in s){
            if(sourceLookup.ContainsKey(char_s)){
                sourceLookup[char_s] += 1;
            }
            else{
                sourceLookup[char_s] = 1;
            }
        }

        foreach(var char_t in t){
            if(sourceLookup.ContainsKey(char_t)){
                sourceLookup[char_t] -= 1;
                if(sourceLookup[char_t] < 0){ 
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
}