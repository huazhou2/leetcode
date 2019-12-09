from typing import List
class Solution:
    def maxSubArray(self, nums:List[int] ) -> int:
        n=len(nums)

        def maxSub(nums,start,end):
            if start==end:
                return nums[start]
            else:
                mid=(start+end)//2
                return max(maxSub(nums,start,mid),maxSub(nums,mid+1,end),crossSum(nums,start,end,mid))
        def crossSum(nums,start,end,mid):
            left_max=float('-inf')
            cur_sum=0
            for i in range(mid,start-1,-1):
                cur_sum+=nums[i]
                left_max=max(left_max,cur_sum)
            cur_sum=0
            right_max=float('-inf')
            for i in range(mid+1,end+1):
                cur_sum+=nums[i]
                right_max=max(cur_sum,right_max)
            return left_max+right_max


        return maxSub(nums,0,n-1)

a=Solution()

nums=[-2,1,-3,4,-1,2,1,-5,4]

a.maxSubArray(nums)