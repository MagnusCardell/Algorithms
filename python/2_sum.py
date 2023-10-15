from typing import List 

def twoSum(nums: List[int], target: int) -> List[int]:
    memo = {}
    for i, n in enumerate(nums):
        if(n in memo):
            return [memo[n], i]
        
        complement = target - n
        memo[complement] = i
    return []


assert twoSum([1,2,3], 4) == [0,2], "example"
assert twoSum([1,2,3], 10) == [], "negative example"
assert twoSum([1,2,3,-1], 1) == [1,3], "negative numbers"
