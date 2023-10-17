from typing import List
def maxSubArray(nums: List[int]) -> int:
    greedyMemory = 0
    sum = 0
    for n in nums:
        sum += n
        greedyMemory = max(sum, greedyMemory)
        if(sum < 0):
            sum = 0
        
    return greedyMemory

assert maxSubArray([-2,1,-3,4,-1,2,1,-5,4]) == 6
assert maxSubArray([1]) == 1
assert maxSubArray([5,4,-1,7,8]) == 23