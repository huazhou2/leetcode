class Solution(object):
    def transpose(self, A):
        """
        :type A: List[List[int]]
        :rtype: List[List[int]]
        """
        r,c=len(A),len(A[0])
        res=[[0]*r for i in range(c)]
        for i in range(r):
            for j in range(c):
                res[j][i]=A[i][j]
        return res

a=Solution()
A=[[1,2,3],[4,5,6],[7,8,9]]
print(a.transpose(A))