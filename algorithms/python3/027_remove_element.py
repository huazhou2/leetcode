class Solution:
    def removeElement(self, nums, val):
        i=0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i]=nums[j]
                i+=1
        return i


nums=[0,1,2,2,3,0,4,2]
a=Solution()

print(a.removeElement(nums,2))


