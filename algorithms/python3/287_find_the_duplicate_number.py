class Solution(object):
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)):
            while nums[i]!=i+1:
                if nums[i]==nums[nums[i]-1]:
                    return nums[i]
                cur=nums[nums[i]-1]
                nums[i],nums[cur]=nums[cur],nums[i]

a=Solution()

nums=[3,1,3,4,2]

print(a.findDuplicate(nums))