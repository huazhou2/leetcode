class Solution(object):
    def maxScoreSightseeingPair(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        maxb=[0]
        n=len(A)
        for i in range(n):
            maxb.append(max(maxb[-1],A[i]+i))

        res=0
        for i in range(1,n):
            res=max(maxb[i]+A[i]-i,res)
        return res





a=Solution()

print(a.maxScoreSightseeingPair([8,1,5,2,6]))