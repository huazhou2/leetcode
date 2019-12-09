from typing import List
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        col0=False
        r,c=len(matrix),len(matrix[0])
        for i in range(r):
            if matrix[i][0]==0:
                col0=True
            for j in range(1,c):
                if matrix[i][j]==0:
                    matrix[i][0]=0
                    matrix[0][j]=0

        for i in range(1,len(matrix)):
            for j in range(1,len(matrix[0])):
                if not matrix[i][0] or not matrix[0][j]:
                    matrix[i][j]=0

        if matrix[0][0]==0:
            for j in range(len(matrix[0])):
                matrix[0][j]=0
        if col0:
            for j in range(len(matrix)):
                matrix[j][0]=0

a=Solution()

nums=[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]