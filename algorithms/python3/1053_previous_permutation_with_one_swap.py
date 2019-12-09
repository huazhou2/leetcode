class Solution(object):
    def prevPermOpt1(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        n=len(A)
        ind=None
        for i in range(n-2,-1,-1):
            if A[i]>A[i+1]:
                ind=i
                break

        if ind==None:
            return A
        max_ind=ind+1
        for i in range(ind+1,n):
            if A[i]>A[max_ind] and A[i]<A[ind]:
                max_ind=i

        A[ind],A[max_ind]=A[max_ind],A[ind]
        return A
a=Solution()

print(a.prevPermOpt1([1,9,4,6,7]))
