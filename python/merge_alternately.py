class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n1 = len(word1)
        n2 = len(word2)
        i = 0
        result = ""
        while(i<n1 and i<n2):
            result += word1[i] + word2[i]
            i+=1

        if(i < n1):
            result += word1[i:n1]
        elif(i < n2):
            result += word2[i:n2]

        return result

s = Solution()
assert s.mergeAlternately("","") == "", "example"
assert s.mergeAlternately("a","b") == "ab", "example"
assert s.mergeAlternately("ab","c") == "acb", "example"
assert s.mergeAlternately("a","bc") == "abc", "example"
assert s.mergeAlternately("abc","pqr") == "apbqcr", "example"
assert s.mergeAlternately("abcd","pq") == "apbqcd", "example"
