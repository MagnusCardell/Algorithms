import math
from typing import List

def getSeats(start: int, end: int, k: int) -> int:
  if(start > end):
    return 0
  max_seats = max(math.ceil((end - start) / (k + 1)), 0)
  return max_seats

#O(S log S)
def getMaxAdditionalDinersCount(N: int, K: int, M: int, S: List[int]) -> int:
  result = 0
  start = 1
  end = 1
  for m in sorted(S):
    end = m - K # end is exclusive
    result += getSeats(start, end, K)
    start = m + K + 1 # start is inclusive
  end = N +1
  result += getSeats(start, end, K)
  return result

# O(N * K)
def getOccupiedSeat(n: int, K: int, lookup: set()) -> int:
    for k in range(1, K+1):
        s_k = n+k 
        if(s_k in lookup):
            return s_k
    return -1

def getMaxAdditionalDinersCount2(N: int, K: int, M: int, S: List[int]) -> int:
    additional_seats = 0
    lookup = set() 
    for s in S:
        # make the occupied seats 0-based
        lookup.add(s-1)
    
    n = 0
    while(n < N):
        if(n in lookup):
            n += K
        else:
            next_occupied_seat = getOccupiedSeat(n, K, lookup)
            if(next_occupied_seat > 0):
                n = next_occupied_seat + K + 1
                continue
            additional_seats += 1
            n += K
        n += 1
    print("additional seats", additional_seats)
    return additional_seats

assert getMaxAdditionalDinersCount(0, 1, 0, []) == 0, "base case"
assert getMaxAdditionalDinersCount(10, 1, 2, [2, 6]) == 3, "example 1"
assert getMaxAdditionalDinersCount(15, 2, 3, [11, 6, 14]) == 1, "example 2"