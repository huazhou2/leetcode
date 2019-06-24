class Solution:
    def minSubArrayLen(self, s: int, nums: List[int]) -> int:
        l=len(nums)
        left=0
        min_len=len(nums)+1
        cur_sum=0
        for i in range(l):
            cur_sum+=nums[i]
            while cur_sum>=s:
                min_len=min(min_len,i-left+1)
                cur_sum-=nums[left]
                left+=1
        if min_len==len(nums)+1:
            return 0
        else:
            return min_len

a=Solution()
nums=[2,3,1,2,4,3]
print(a.minSubArrayLen(7,nums))
