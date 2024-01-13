public class Solution {

    public string Encode(IList<string> strs) {
        var sb = new StringBuilder();
        for(int i = 0; i<strs.Count; ++i){
            var s = strs[i];
            sb.Append(s);
            //if(i != strs.Count-1){
            sb.Append(";");    
            //}
        }
        return sb.ToString();
    }

    public List<string> Decode(string s) {
        if(s == "") return new List<string>();

        var parts_arr = s.Split(";");
        var parts = parts_arr.ToList().Take(parts_arr.Count()-1);
        return parts.ToList();
   }

}

