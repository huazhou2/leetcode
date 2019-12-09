class Solution:
    def searchRange(self, nums, target):
        res=[-1,-1]
        left=self.bins(nums,target-0.1,0,len(nums)-1)
        right=self.bins(nums,target+0.1,0,len(nums)-1)
        if left<right:
            res=[left+1,right]
        return res

    def bins(self,nums,target,start,end):
        if start>end:
            return end
        mid=(start+end)//2
        if target>nums[mid]:
            return self.bins(nums,target,mid+1,end)
        else:
            return self.bins(nums,target,start,mid-1)


a=Solution()

nums=[5,7,7,8,8,10]

print(a.searchRange(nums,8))