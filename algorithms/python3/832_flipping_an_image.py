class Solution(object):
    def flipAndInvertImage(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        r,c=len(A),len(A[0])
        for i in range(r):
            for j in range((c+1)//2):
                A[i][j],A[i][-j-1]=1-A[i][-j-1],1-A[i][j]
        return A




a=Solution()

A=[[1,1,0],[1,0,1],[0,0,0]]
a.flipAndInvertImage(A)