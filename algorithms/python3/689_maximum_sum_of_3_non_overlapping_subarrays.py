class Solution(object):
    def maxSumOfThreeSubarrays(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        W=[]
        sum_=0
        for i,x in enumerate(nums):
            sum_+=x
            if i>=k:
                sum_-=nums[i-k]
            if i>=k-1:
                W.append(sum_)

        left=[0]*len(W)
        best=0

        for i in range(len(W)):
            if W[i]>W[best]:
                best=i
            left[i]=best

        right=[0]*len(W)
        best=len(W)-1
        for i in range(len(W)-1,-1,-1):
            if W[i]>=W[best]:
                best=i
            right[i]=best

        ans=None

        for j in range(k,len(W)-k):
            ll,rr=left[j-k],right[j+k]
            if ans is None or (W[ll]+W[j]+W[rr])> (W[ans[0]]+W[ans[1]]+W[ans[2]]):
                ans=[ll,j,rr]
        return ans

a=Solution()

print(a.maxSumOfThreeSubarrays([1,2,1,2,6,7,5,1],2))


