class Solution(object):
    def findLengthOfLCIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        max_val=0
        cur=1
        start=1
        while start<len(nums):
            if nums[start]>nums[start-1]:
                cur+=1
            else:
                max_val=max(max_val,cur)
                cur=1
            start+=1
        return max(max_val,cur)

a=Solution()
print(a.findLengthOfLCIS([1,3,5,4,7]))


