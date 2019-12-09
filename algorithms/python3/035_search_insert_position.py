class Solution:
    def searchInsert(self, nums, target):
        start,end=0,len(nums)-1
        while start<=end:
            if nums[mid]==target:
                return mid
                end=mid-1
            elif nums[mid]>target:
                pass
            else:
                start=mid+1
            mid=(start+end)//2
        return start



a=Solution()

nums=[1,3,5,6]

print(a.searchInsert(nums,5))

