class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(str1 == "" or str2 == ""): 
            return ""
        long = ""
        short = ""
        if(len(str1) > len(str2)):
            short = str2
            long = str1
        else:
            short = str1
            long = str2
        a = short + long
        b = long + short
        if(a != b):
            return ""
        
        # euclidian algo for gcd
        x = len(long)
        y = len(short)
        r = 0
        while((x % y) > 0):
            r = x%y
            x = y
            y = r
        
        return short[0:y]
    
    def gcdOfStrings2(self, str1: str, str2: str) -> str:
        if(str1 == "" or str2 == ""): 
            return ""
        divisor = ""
        rest = ""
        if(len(str1) > len(str2)):
            divisor = str2
            rest = str1
        else:
            divisor = str1
            rest = str2
        dN = len(divisor)

        gcd = dN
        while(len(rest) % gcd != 0 and gcd > 1):
            gcd = gcd//2
        
        while (gcd > 0):
            for y in range(len(rest)):
                if(gcd <=1):
                    return ""
                if( divisor[y % gcd] != rest[y]):
                    gcd = gcd//2
                    continue
            return divisor[0:gcd]
        return ""

s = Solution()
assert s.gcdOfStrings("", "") == "", "empty"
assert s.gcdOfStrings("ABCABC", "ABC") == "ABC", "ABC case"
assert s.gcdOfStrings("ABABAB", "ABAB") == "AB", "AB case"
assert s.gcdOfStrings("LEET", "CODE") == "", "none case"