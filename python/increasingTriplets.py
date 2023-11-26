class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if(len(nums) < 3):
            return False
        
        i = nums[0]
        j = None
        n = 1
        while(n<len(nums)):
            if(i<nums[n]):
                j = nums[n]
                n += 1
                break
            else:
                i = nums[n]
            n += 1
        if not j and j != 0:
            return False

        k = None
        while(n<len(nums)):
            if(j < nums[n]):
                return True
            else:
                if i < nums[n]:
                    j = nums[n]
                else:
                    if not k and k != 0:
                        k = nums[n]
                    else:
                        if nums[n] > k:
                            i = k
                            j = nums[n]
                            k = None
                        else:
                            k = nums[n]
            n += 1
        return False

            

#        for i in range(0, len(nums)-2):
#            for j in range(i+1, len(nums)-1):
#                for k in range(j+1, len(nums)):
#                    if(nums[i] < nums[j] and nums[j] <nums[k]):
#                        return True
#        return False