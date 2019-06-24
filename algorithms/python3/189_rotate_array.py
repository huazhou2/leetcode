class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        def helper(nums,left,right):
            mid=(left+right+1)//2
            for i in range(left,mid):
                nums[i],nums[right-i+left]=nums[right-i+left],nums[i]

        k%=len(nums)
        helper(nums,0,len(nums)-1)
        helper(nums,0,k-1)
        helper(nums,k,len(nums)-1)

a=Solution()
nums=[1,2,3,4,5,6,7]
a.rotate(nums,3)
