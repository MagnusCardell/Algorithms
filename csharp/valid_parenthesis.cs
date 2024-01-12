public class Solution {
    public bool IsValid(string s) {

        var trace = new Stack<char>();
        foreach(var c in s){
            char top;
            if(c == '(') trace.Push('(');
            else if(c == '{') trace.Push('{');
            else if(c == '[') trace.Push('[');
            else{
                if(trace.Count == 0) return false;
                if(c == ')') {
                    top = trace.Pop();
                    if(top != '(') return false;
                }
                else if(c == '}') {
                    top = trace.Pop();
                    if(top != '{') return false;
                }
                else if(c == ']') {
                    top = trace.Pop();
                    if(top != '[') return false;
                }
            }
            
        }
        return trace.Count == 0;
    }
}