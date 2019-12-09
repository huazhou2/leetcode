class Solution(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """

        memo=[[0]*(len(B)+1) for i in range(len(A)+1)]

        for i in range(len(A)-1,-1,-1):
            for j in range(len(B)-1,-1,-1):
                if A[i]==B[j]:
                    memo[i][j]=memo[i+1][j+1]+1
        return max([max(line) for line in memo])

a=Solution()

A= [1,2,3,2,1]
B= [3,2,1,4,7]

print(a.findLength(A,B))
