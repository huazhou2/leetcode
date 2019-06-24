class Solution:
    def firstMissingPositive(self, nums):
        if (len(nums)==0):
            return 1
        for i in range(0,len(nums)):
            while nums[i]!=i+1:
                if nums[i]<=0 or nums[i]>len(nums) or nums[i]==nums[nums[i]-1]:
                    break
                ind=nums[i]-1
                nums[i],nums[ind]=nums[ind],nums[i]
        for i in range(0,len(nums)):
            if nums[i]!=i+1:
                return i+1


a=Solution()

print(a.firstMissingPositive([3,4,1,-1]))

