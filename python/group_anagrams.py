import collections
from typing import List
def group_anagrams(strs: List[str]) -> List[List[str]]:

    lookup = collections.defaultdict(list)
    for str in strs:
        # create key, 
        key = [0] * 26
        for x in str:
            key[ord(x) - ord('a')] += 1
        # check key against dictionary, add to or create
        lookup[tuple(key)].append(str)
    
    result: List[List[str]] = []
    for x in lookup.keys():
        result.append(lookup[x])

    print(result)
    return result

assert group_anagrams(["cat", "tac", "ars"]) == [["cat", "tac"], ["ars"]], "example"
assert group_anagrams(["eat","tea","tan","ate","nat","bat"]) == [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']], "example2"
assert group_anagrams([""]) == [[""]], "example3"
assert group_anagrams(["a"]) == [["a"]], "example4"