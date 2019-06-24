class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        left=0
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[i],nums[left]=nums[left],nums[i]
                left+=1

a=Solution()

nums=[0,1,0,3,12]

a.moveZeroes(nums)

