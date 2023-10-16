import collections
from typing import List
def threeSum(nums: List[int]) -> List[List[int]]:
    target = 0
    result = {}
    s = sorted(nums)
    for i, t in enumerate(s):
        lookup = {}
        for j in range(i+1, len(s)):
            v = s[j]
            if v in lookup:
                w = lookup[v]
                key = f"{t}{w}{v}"
                result[key] = [t,w, v]
            else:
                complement = target - v - t
                lookup[complement] = v 

    return list(result.values())


assert threeSum([-1,0,1,2,-1,-4]) == [[-1,-1,2],[-1,0,1]], "example 1"
assert threeSum([0,1,1]) == [], "negative case 1"