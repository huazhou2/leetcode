from typing import List
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m,n=len(obstacleGrid),len(obstacleGrid[0])

        res=[[0]*n for _ in range(m)]
        for i in range(m-1,-1,-1):
            if obstacleGrid[i][n-1]==0:
                res[i][n-1]=1
            else:
                break

        for i in range(n-1,-1,-1):m-1
            if obstacleGrid[m-1][i]==0:
                res[m-1][i]=1
            else:
                break
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                if obstacleGrid[i][j]==1:
                    res[i][j]=0
                else:
                    res[i][j]=res[i+1][j]+res[i][j+1]
        return res[0][0]

a=Solution()

print(a.uniquePathsWithObstacles([[0,0,0], [0,1,0], [0,0,0]]))
