class Solution:
    def isVowel(self, s: str) -> bool:
        c = s.lower()
        vowels = "aeiou"
        if(c in vowels):
            return True
        return False

    def reverseVowels(self, s: str) -> str:
        arr = list(s)
        leftP = 0
        rightP = len(s)-1

        while(leftP <= rightP):
            letfIsVowel = self.isVowel(arr[leftP])
            rightIsVowel = self.isVowel(arr[rightP])
            if(letfIsVowel and rightIsVowel):
                temp = arr[leftP]
                arr[leftP] = arr[rightP]
                arr[rightP] = temp
                leftP +=1
                rightP -= 1
            elif(rightIsVowel == False):
                rightP -= 1
            elif(letfIsVowel == False):
                leftP += 1
        return "".join(arr)