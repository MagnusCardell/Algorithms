import string

def binary_search(n: [int], v: int) -> bool:
    low = 0
    high = len(n)

    while(low < high):
        m = low + (high - low) // 2
        mid = n[m]
        if(mid == v):
            return True
        elif(v > mid):
            low = m + 1
        elif(v < mid):
            high = m
    return False


assert binary_search([], 0) == 0, "negative case"
assert binary_search([1,2,3], 2) == 1, "base case"
assert binary_search([1,2,3], 3) == 1, "upper"
assert binary_search([1,2,3], 1) == 1, "lower"

print("all cases pass")