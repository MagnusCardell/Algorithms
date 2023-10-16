from typing import List

def rob(nums: List[int]) -> int:
    greedy = 0
    previous = 0
    for h in nums:
        optimist = max(h + previous, greedy)
        previous = greedy
        greedy = optimist
    return greedy

assert rob([1,2,3,1]) == 4 