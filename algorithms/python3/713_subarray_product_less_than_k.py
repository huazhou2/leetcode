class Solution(object):
    def numSubarrayProductLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if k<=1:
            return 0
        prod=1
        ans=left=0
        for right,val in enumerate(nums):
            prod*=val
            while prod>=k:
                prod/=nums[left]
                left+=1
            ans+=right-left+1
        return ans

    def numSubarrayProductLessThanK2(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        self.cnt=0
        def helper(nums,pos,cur):
            if pos>=len(nums):
                return
            if cur*nums[pos]<k:
                self.cnt+=1
                helper(nums,pos+1,cur*nums[pos])
        for i in range(len()):
            helper(nums,i,1)
        return self.cnt

a1=Solution()

print(a1.numSubarrayProductLessThanK([10,5,2,6],100))


