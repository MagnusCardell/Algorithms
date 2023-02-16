public class Solution {
    //time complexity O(n+k) solution
    // put each element in bucket
    // use the bounded relation of 'k' to bucket-sort in n+k time
    public int[] TopKFrequent(int[] nums, int k) {
         var lookupCounter = new Dictionary<int, int>();
        foreach(var num in nums){
            if(lookupCounter.ContainsKey(num)){
                lookupCounter[num] += 1;
            }
            else{
                lookupCounter[num] = 1;
            }
        }
        var bucketCount = new List<int>[nums.Count()];
        foreach(var countEntry in lookupCounter){
            if(bucketCount[countEntry.Value-1] != null){
                bucketCount[countEntry.Value-1].Add(countEntry.Key);
            }
            else{
                bucketCount[countEntry.Value-1] = new List<int>{countEntry.Key};
            }
        }
        var topK = new List<int>();
        var remainder = k;
        var bucketIndex = bucketCount.Count() -1;
        while(remainder > 0){
            var bucket = bucketCount[bucketIndex];
            if(bucket == null) {
                bucketIndex -= 1;
                continue;
            }
            var bucketSize = bucket.Count;
            if(bucketSize > remainder){
                topK.AddRange(bucketCount[bucketIndex].Take(remainder));
                remainder = 0;
            }
            else{
                topK.AddRange(bucketCount[bucketIndex]);
                remainder -= bucketCount[bucketIndex].Count;
            }
            bucketIndex -= 1;
        }

        return topK.ToArray();
    }
}
// n log(n) solution
// put each element in buckets,
// sort by frequency, and pick first k elements
public class Solution2 {
    public int[] TopKFrequent(int[] nums, int k) {
        var lookupCounter = new Dictionary<int, int>();
        foreach(var num in nums){
            if(lookupCounter.ContainsKey(num)){
                lookupCounter[num] += 1;
            }
            else{
                lookupCounter[num] = 1;
            }
        }
        
        var sortedCount = lookupCounter.OrderByDescending(x => x.Value);
        return sortedCount.Take(k).Select(x => x.Key).ToArray();
        
    }
}