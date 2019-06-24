class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        res=0
        for i in range(len(nums)):
            res=res+i+1-nums[i]
        return res

a=Solution()

print(a.missingNumber([9,6,4,2,3,5,7,0,1]))