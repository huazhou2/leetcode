class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        for i in range(len(nums)):
            if i%2:
                max_val=max(nums[i-1:i+2])
                if  max_val==nums[i]:
                    continue
                elif max_val==nums[i-1]:
                    nums[i-1],nums[i]=nums[i],nums[i-1]
                else:
                    nums[i],nums[i+1]=nums[i+1],nums[i]


a=Solution()
nums = [3,5,2,1,6,4]
a.wiggleSort(nums)

