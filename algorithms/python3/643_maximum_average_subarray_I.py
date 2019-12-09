class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        if len(nums)<k:
            return None
        ans=sum(nums[0:k])
        max_val=ans
        for i in range(1,len(nums)-k+1):
            ans=ans-nums[i-1]+nums[i+k-1]
            max_val=max(max_val,ans)

        return max_val/k

a1=Solution()

print(a1.findMaxAverage([1,12,-5,-6,50,3],4))