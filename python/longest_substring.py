def lengthOfLongestSubstring(s: str) -> int:

    mLength = 0
    p1 = 0
    p2 = 0
    if(len(s) <= 1):
        return len(s)
    
    memo = set()
    while(p1 < len(s) and p2 < len(s)):
        
        while(s[p2] in memo):
            memo.remove(s[p1])
            p1 += 1
        memo.add(s[p2])
        mLength = max(mLength, p2 - p1  + 1)
        p2 += 1
    return mLength

assert lengthOfLongestSubstring("a") == 1, "base"
assert lengthOfLongestSubstring("") == 0, "empty"
assert lengthOfLongestSubstring("abc") == 3, "abc"
assert lengthOfLongestSubstring("aabc") == 3, "aabc"
assert lengthOfLongestSubstring("abcabcbb") == 3, "abcabcbb"
assert lengthOfLongestSubstring("aaaaaaaaaa") == 1, "aaaaaaaaaaa"


