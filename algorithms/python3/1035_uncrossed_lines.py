class Solution(object):
    def maxUncrossedLines(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        n1,n2=len(A),len(B)
        mat=[[0] * (n2 +1) for _ in range(n1+1)]

        for i in range(n1-1,-1,-1):
            for j in range(n2-1,-1,-1):
                if A[i]==B[j]:
                    mat[i][j]=max(mat[i+1][j+1]+1,mat[i+1][j],mat[i][j+1])
                else:
                    mat[i][j]=max(mat[i+1][j+1],mat[i+1][j],mat[i][j+1])
        return mat[0][0]


a=Solution()

A = [1,4,2]
B = [1,2,4]

print(a.maxUncrossedLines(A,B))





