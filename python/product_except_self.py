from typing import List
def productExceptSelf(nums: List[int]) -> List[int]:
  # right to left
  left = [1] * len(nums)
  for i in range(len(nums) -2, -1, -1):
    left[i] = nums[i+1] * left[i+1]
  right = [1] * len(nums)
  for i in range(1, len(nums)):
    right[i] = nums[i-1] * right[i-1]
  result = []
  for i in range(0, len(nums)):
    result.append(right[i] * left[i])
  return result

assert productExceptSelf([1,2,3,4]) == [24,12,8,6], "example 1"
assert productExceptSelf([-1,1,0,-3,3]) == [0,0,9,0,0], "example 2"
print("All tests pass")