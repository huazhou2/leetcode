from typing import List

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        tmp=sorted(nums)
        l,r=len(nums)-1,0
        for i in range(len(nums)):
            if nums[i] != tmp[i]:
                l=min(l,i)
                r=max(r,i)
        if r>l:
            return r-l+1
        else:
            return 0

a1=Solution()

print(a1.findUnsortedSubarray([1,2,3,4]))


