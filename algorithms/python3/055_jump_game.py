class Solution:
    def canJump(self, nums):
       if (len(nums)<=1):
           return True
       far=len(nums)-1
       for i in range(len(nums)-2,-1,-1):
            if i+nums[i]>=far:
                far=i
        return far==0
    def canJump2(self, nums):
        if (len(nums)<=1):
            return True
        k=1
        for i in range(len(nums)-2,-1,-1):
            if nums[i]<k:
                k+=1
            else:
                k=1
        return k==1


a=Solution()


print(a.canJump2([2,3,1,1,4]))
print(a.canJump2([3,2,1,0,4]))