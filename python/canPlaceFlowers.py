from typing import List
class Solution:
    def getNumberOfFlowers(self, start, end)-> int:
        return max((end-start)//2, 0)

    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        lastFlower = -2
        for i in range(len(flowerbed)):
            pot = flowerbed[i]
            if(pot == 1):
                x = self.getNumberOfFlowers(lastFlower+2, i)
                n -= x 
                if(n <=0):
                    return True
                lastFlower = i
        
        x = self.getNumberOfFlowers(lastFlower+2, i+2)
        n -= x 
        if(n <=0):
            return True
        return False
    
s = Solution()
assert s.canPlaceFlowers([1,0,0,0,1], 1) == True, "ex 1"
assert s.canPlaceFlowers([1,0,0,0,1], 2) == False, "ex 2"
assert s.canPlaceFlowers([1,0,0,0,0,1], 2) == False, "ex 3"