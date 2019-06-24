from typing import List
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if not nums:
            return 0
        record=[nums[0]]*2
        res=nums[0]

        for cur in nums[1:]:
            record=[min(record[0]*cur,cur,record[1]*cur),max(record[0]*cur,cur,record[1]*cur)]
            res=max(res,record[1])
        return res

a=Solution()

nums=[2,3,-2,4]
print(a.maxProduct(nums))