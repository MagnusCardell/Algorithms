// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

public class Solution {
    //Approach 1 - sort and group: time complexity O(n logn), memory O(n)
        // foreach sorted str in str (O(nlogn)) -> key
        // use key to lookup if we've seen it before and group accordingly
        // return groups
    //Approach 2 - lookup and group: time: O(n), memory O(n)
        // since str is bounded - loop through each character, create lookup key O(100n) -> O(n)
        // group according to key O(1)
        // format groups into return lists O(n)
    public IList<IList<string>> GroupAnagrams(string[] strs) {
        //Approach 2
        var returnList = new List<IList<string>>();
        var anagramLookup = new Dictionary<string, IList<string>>();

        foreach(var str in strs){
            //create key - assume lowercase english
            var anagramKey = new int[26];
            foreach(var chr in str){
                //cast character to ascii code and set a = 0
                anagramKey[(int)chr -97] += 1;
            }
            var key = "";
            foreach(var entry in anagramKey){
                //separate each count to account for base 10
                key +=$"{entry},";
            }
            // dont care about uniqueness here
            if(anagramLookup.ContainsKey(key)){
                anagramLookup[key].Add(str);
            }
            else{
                anagramLookup[key] = new List<string>{str};
            }
        }
        //format lookup into return list
        foreach(var entry in anagramLookup){
            returnList.Add(entry.Value);
        }
        return returnList;
    }

//Approach 1
    public IList<IList<string>> GroupAnagrams1(string[] strs) {
        var groupLookup = new Dictionary<string, List<string>>();
        foreach(var str in strs){
            var chars = str.ToArray();
            Array.Sort(chars);
            var orderedStr = new string( chars );
            if(groupLookup.ContainsKey(orderedStr)){                
                groupLookup[orderedStr].Add(str);
            }
            else{
                groupLookup[orderedStr] = new List<string>(){ str };
            }   
        }
        
        var groups = new List<IList<string>>();
        var keys = groupLookup.Keys.ToList();
        foreach(var k in keys ){
            groups.Add(groupLookup[k]);
        }
        return groups;
    }
}