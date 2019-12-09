class Solution(object):
    def maxSubarraySumCircular(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n=len(A)
        ans=cur=float('-inf')
        for item in A:
            cur=item+max(0,cur)
            ans=max(ans,cur)
        ###doing split interval for each i

        rightsums=[None]*n
        rightsums[-1]=A[-1]
        for i in range(n-2,-1,-1):
            rightsums[i]=A[i]+rightsums[i+1]

        rightmax=[None]*n
        curmax=rightmax[-1]=A[-1]
        for i in range(n-2,-1,-1):
            curmax=max(curmax,rightsums[i])
            rightmax[i]=curmax
        ##leftsum
        leftsum=0
        for i in range(0,n-2):
            leftsum+=A[i]
            ans=max(ans,leftsum+rightmax[i+2])
        return ans








a=Solution()

print(a.maxSubarraySumCircular([5,-3,5]))