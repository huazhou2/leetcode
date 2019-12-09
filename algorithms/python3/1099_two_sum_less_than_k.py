class Solution(object):
    def twoSumLessThanK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        A.sort()
        i,j=0,len(A)-1
        res=-1
        while i<j:
            if A[i]+A[j]>=K:
                j-=1
            else:
                res=max(res,A[i]+A[j])
                i+=1
        return res

a=Solution()

A = [34, 23, 1, 24, 75, 33, 54, 8]
K = 60

print(a.twoSumLessThanK(A,K))

