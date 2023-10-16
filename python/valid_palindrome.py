def isPalindrome(s: str) -> bool:
    t = ""
    for c in s:
        if((ord(c) >96 and ord(c) < 123) or (ord(c) > 64 and ord(c) < 91) or (ord(c) < 58 and ord(c) > 47)):
            if(ord(c) < 91 and ord(c) > 57):
                c = chr(ord(c) + 32)
            t += c
    print(t)
    p1 = 0
    p2 = len(t) -1
    while (p1 < p2):
        if(t[p1] != t[p2]):
            return False
        p1 += 1
        p2 -= 1
    return True

assert isPalindrome("anna") == True, "anna"
assert isPalindrome(" ") == True, "empty"
assert isPalindrome("A man, a plan, a canal: Panama") == True, "a man a plan"
assert isPalindrome("ab") == False, "negative 1"
assert isPalindrome("race a car") == False, "negative 2"
assert isPalindrome("p0") == False, "numerical"

print("all tests pass")