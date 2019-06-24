class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        sum=0
        ans=0
        sumset={0:1}
        for i in range(len(nums)):
            sum+=nums[i]
            if sum-k in sumset:
                ans+=sumset[sum-k]
            if sum in sumset:
                sumset[sum]+=1
            else:
                sumset[sum]=1
        return ans

a=Solution()
print(a.subarraySum([1,1,1],2))


