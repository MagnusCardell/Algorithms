from typing import List
def maxArea(height: List[int]) -> int:
    maxarea = 0
    l = 0
    r = len(height)-1
    while(l < r):
        length = r - l 
        h = min(height[l], height[r])
        maxarea = max(length * h, maxarea)

        if(height[l] < height[r]):
            l += 1
        elif(height[r] <= height[l]):
            r -= 1
    print(maxarea)
    return maxarea

assert maxArea([1,1]) == 1, "base"
assert maxArea([1,8,6,2,5,4,8,3,7]) == 49, "example"