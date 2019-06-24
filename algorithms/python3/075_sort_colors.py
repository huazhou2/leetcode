class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left,right,cur=0,len(nums)-1,0
        while cur<=right:
            if nums[cur]==2:
                nums[cur],nums[right]=nums[right],nums[cur]
                right-=1
            elif nums[cur]==0:
                nums[cur],nums[left]=nums[left],nums[cur]
                cur+=1
                left+=1
            else:
                cur+=1

a=Solution()

nums=[2,0,2,1,1,0]

a.sortColors(nums)

