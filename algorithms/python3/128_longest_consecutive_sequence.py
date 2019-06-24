from typing import List
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res=0
        numset=set(nums)
        for curnum in numset:
            if not curnum-1 in numset:
                curlen=0
                while curnum in numset:
                    curlen+=1
                    res=max(res,curlen)
                    curnum+=1
        return res


a=Solution()
nums=[100, 4, 200, 1, 3, 2]

print(a.longestConsecutive(nums))