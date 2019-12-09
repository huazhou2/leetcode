class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m,n=len(grid),len(grid[0])
        res=[[grid[m-1][n-1]]*n for i in range(m)]

        for i in range(m-2,-1,-1):
            res[i][n-1]=res[i+1][n-1]+grid[i][n-1]
        for i in range(n-2,-1,-1):
            res[m-1][i]=res[m-1][i+1]+grid[m-1][i]
        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                res[i][j]=grid[i][j]+min(res[i+1][j],res[i][j+1])
        return res[0][0]

a=Solution()

print(a.minPathSum([ [1,3,1], [1,5,1], [4,2,1]]))
