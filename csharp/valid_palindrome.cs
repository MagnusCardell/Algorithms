public class Solution {
    public bool IsPalindrome(string s) {
        var cleanS = "";
        foreach(var c in s){
            if( (c >= 48 && c <= 57) ||
                (c >= 97 && c <= 122) || 
                (c >= 65 && c <= 90) ){
                cleanS += c.ToString().ToLower();
            }
        }

        var i = 0;
        var j = cleanS.Length -1;
        while(i<=j){
            if(cleanS[i] != cleanS[j]){
                return false;
            }
            i+= 1;
            j-= 1;
        }
        return true;
    }
}