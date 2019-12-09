class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        def helper(nums,start,end,target):
            if start>end:
                return False
            mid=(start+end)//2
            if nums[mid]==target:
                return True
            if nums[mid]>nums[start]:
                if nums[mid]>target and target>=nums[start]:
                    return helper(nums,start,mid-1,target)
                else:
                    return helper(nums,mid+1,end,target)

            elif nums[mid]<nums[start]:
                if nums[mid]<target and target<=nums[end]:
                    return helper(nums,mid+1,end,target)
                else:
                    return helper(nums,start,mid-1,target)
            else:
                return helper(nums,start+1,end,target)
        return helper(nums,0,len(nums)-1,target)


a=Solution()

nums=[2,5,6,0,0,1,2]
a.search(nums,3)

