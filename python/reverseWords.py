class Solution:
    def reverseWords(self, s: str) -> str:
        result = []
        buffer = ""
        for i in range(len(s)-1, -1, -1):
            if(ord(s[i]) == 32 and len(buffer) > 0):
                result.append(buffer[::-1])
                buffer = ""
            elif(ord(s[i]) != 32):
                buffer += s[i]
        if (len(buffer) > 0):
            result.append(buffer[::-1])
        return " ".join(result)