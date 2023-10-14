import string 

def linear_search(n: string, v: string) -> int:
    for i, c in enumerate(n):
        if c == v:
            return i
    return -1

assert linear_search("a", "a") == 0, "base case"
assert linear_search("a", "b") == -1, "negative case"
assert linear_search("abcdefg", "g") == 6, "longer case"

print("all cases pass")
