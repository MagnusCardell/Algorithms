from typing import List


class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        threshold = 0
        for candy in candies:
            threshold = max(threshold, candy)
        result: List[bool] = []
        for candy in candies:
            result.append((candy + extraCandies) >= threshold)
        return result

s = Solution()
assert s.kidsWithCandies([1,2,3,4], 2) == [False, False, True, True], "example 1"
assert s.kidsWithCandies([4,2,1,1,2], 1) == [True, False, False, False, False], "example 2"
assert s.kidsWithCandies([12,1,12], 10) == [True, False, True], "example 3"
        
