class Solution(object):
    def maxWidthRamp(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        ans=0
        m=float('inf')

        idx=sorted(range(len(A)),key=lambda x: A[x])

        for i in idx:
            ans=max(ans,i-m)
            m=min(i,m)
        return ans


a=Solution()

print(a.maxWidthRamp([6,0,8,2,1,5]))
