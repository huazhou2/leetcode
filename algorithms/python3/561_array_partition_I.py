class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res=0
        nums.sort()
        for i in range(len(nums)):
            if i%2==0:
                res+=nums[i]
        return res

a=Solution()
print(a.arrayPairSum([1,4,3,2]))