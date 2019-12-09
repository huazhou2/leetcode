class Solution(object):
    def sumSubseqWidths(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        mod=10**9+7
        res=0
        N=len(A)
        pow2=[1]
        for i in range(1,N):
            pow2.append(pow2[-1]*2 % mod)
        for i,x in enumerate(A):
            res=(res+(pow2[i]-pow2[-1-i])*x) % mod
        return res


a=Solution()

print(a.sumSubseqWidths([2,1,3]))
