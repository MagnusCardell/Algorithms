import string
def valid_anagram(s: string, t: string) -> bool:
    if len(s) != len(t):
        return False
    
    s_map = {}
    for x in s:
        s_map[x] = s_map.get(x, 0) + 1

    t_map = {}
    for x in t:
        t_map[x] = t_map.get(x, 0) + 1
    
    return s_map == t_map

assert valid_anagram("a", "a") == True, "pos base"
assert valid_anagram("a", "b") == False, "neg base"
assert valid_anagram("a", "a") == True, "base"
assert valid_anagram("anagram", "nagaram") == True, "example nagaram"
assert valid_anagram("nagaram", "anagram") == True, "example nagaram2"
assert valid_anagram("anagram", "bananas") == False, "example negative"
print("all tests pass")