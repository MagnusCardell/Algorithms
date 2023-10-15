from typing import List
import collections

def topKFrequent(nums: List[int], k: int) -> List[int]:
  count = {}
  for x in nums:
    count[x] = count.get(x, 0) + 1
  
  freqs = [ [] for x in range(len(nums))]
  for n, x in count.items():
    freqs[x].append(n)
  
  result = []
  #walk backwards
  for i in range(len(freqs)-1, 0, -1):
    for x in freqs[i]:
       result.append(x)
       if(len(result) == k):
          return result

def topKFrequent2(nums: List[int], k: int) -> List[int]:
        count = collections.defaultdict(int)
        for n in nums:
            count[n] = count.get(n, 0) + 1
        
        s = sorted(count.items())
        return [x[0] for x in s[:k]]

assert topKFrequent([1,1,1,2,2,3], 2) == [1,2], "example 1"
