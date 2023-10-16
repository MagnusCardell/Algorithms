def minWindow(s: str, t: str) -> str:
    if t == "":
        return ""
    countT = {}
    for c in t:
        countT[c] = countT.get(c, 0) + 1

    have = 0 
    need = len(countT)
    res = [-1,1]
    resLen = float("infinity")
    p1 = 0
    window = {}
    for p2 in range(len(s)):
        c = s[p2]
        window[c] = window.get(c, 0) + 1
        if c in countT and window[c] == countT[c]:
            have += 1
        
        while have == need:
            if((p1-p2 + 1) < resLen):
                resLen = p1-p2+1
                res = [p1, p2]
            window[s[p1]] -= 1
            if(s[p1] in countT and window[s[p1]] < countT[s[p1]]):
                have -= 1
            p1 += 1
    p1 = res[0]
    p2 = res[1]
    print(s[p1:p2])
    return s[p1: p2+1] if resLen != float("infinity") else ""

assert minWindow("ADOBECODEBANC", "ABC") == "BANC"