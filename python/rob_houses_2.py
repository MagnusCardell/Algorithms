from typing import List
def rob(nums: List[int]) -> int:
    return max(nums[0], rob_houses1(nums[1:]), rob_houses1(nums[:-1]))

def rob_houses1(nums: List[int]) -> int:
    greedy = 0
    previous = 0
    for h in nums:
        pragmatist = max(previous + h, greedy)
        previous = greedy
        greedy = pragmatist
    return greedy

assert rob([2,3,2]) == 3
assert rob([1,2,3,1]) == 4