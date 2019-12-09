class Solution:
    def removeDuplicates(self, nums):
        if len(nums)<=1:
            return len(nums)
        i,j=0,1
        res=1
        for j in range(1,len(nums)):
            if nums[j]==nums[i]:
                j+=1
            else:
                i=i+1
                nums[i]=nums[j]
                res+=1
        return res

nums=[0,0,1,1,1,2,2,3,3,4]
a=Solution()
print(a.removeDuplicates(nums))
