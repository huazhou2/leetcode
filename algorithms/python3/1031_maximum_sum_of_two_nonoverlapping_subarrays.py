class Solution(object):
    def maxSumTwoNoOverlap(self, A, L, M):
        """
        :type A: List[int]
        :type L: int
        :type M: int
        :rtype: int
        """
        left_l,right_l,left_m,right_m=[],[],[],[]
        n=len(A)

        ##L in left,M in right
        mysum=sum(A[-M:])
        right_m=[0]*(n-M+1)
        right_m[-1]=mysum
        for i in range(n-M-1,-1,-1):
            mysum+=A[i]-A[i+M]
            right_m[i]=max(mysum,right_m[i+1])


        cur,curmax=sum(A[:L]),sum(A[:L])
        ans=curmax+right_m[L]
        for i in range(L+1,n-M+1):
            cur+=A[i-1]-A[i-L-1]
            curmax=max(curmax,cur)
            ans=max(ans,curmax + right_m[i])

        ##M in left, L in right
        mysum = sum(A[-L:])
        right_m = [0] * (n - L + 1)
        right_m[-1] = mysum
        for i in range(n - L - 1, -1, -1):
            mysum += A[i] - A[i + L]
            right_m[i] = max(mysum, right_m[i + 1])

        cur, curmax = sum(A[:M]), sum(A[:M])
        ans = max(ans,curmax + right_m[M])
        for i in range(M + 1, n - L + 1):
            cur += A[i-1] - A[i - M-1]
            curmax = max(curmax, cur)
            ans = max(ans, curmax + right_m[i])


        return ans


        ##M in left, L in right



a=Solution()
A = [0,6,5,2,2,5,1,9,4]
L = 1
M = 2
print(a.maxSumTwoNoOverlap(A,L,M))














