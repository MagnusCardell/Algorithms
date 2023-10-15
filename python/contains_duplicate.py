from typing import List
def containsDuplicate(nums: List[int]) -> bool:
    memo = set()
    for n in nums:
        if n in memo:
            return True
        memo.add(n)
    return False

assert containsDuplicate([]) == False, "empty"
assert containsDuplicate([1,1]) == True, "true"
assert containsDuplicate([1,2]) == False, "false"
assert containsDuplicate([1,2,34,5,6,7]) == False, "long false"
assert containsDuplicate([1,1231231231231, 1231231, 1]) == True, "long true"


print("all tests pass")