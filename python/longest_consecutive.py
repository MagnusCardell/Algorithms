from typing import List
def longestConsecutive(nums: List[int]) -> int:
    lookup = set()
    for n in nums:
        lookup.add(n)
    
    max = 0
    for n in nums:
        if( n-1 in lookup):
            continue
        count = 1
        t = n + 1
        while(t in lookup):
            count += 1
            t += 1
        if(count > max):
            max = count
        
    return max
    