class Solution:
    ''' this recursive is so time consuming'''
    def uniquePaths2(self, m: int, n: int) -> int:

        def dfs(r,c):
            if r==m-1 and c==n-1:
                return 1
            if r==m-1:
                return dfs(r,c+1)
            if c==n-1:
                return dfs(r+1,c)
            return dfs(r+1,c) +dfs(r,c+1)
        return dfs(0,0)
    '''use dynamic programming'''
    def uniquePaths(self, m: int, n: int) -> int:
        res=[[1]*n for i in range(m)]

        for i in range(m-2,-1,-1):
            for j in range(n-2,-1,-1):
                res[i][j]=res[i+1][j]+res[i][j+1]

        return res[0][0]


a=Solution()

print(a.uniquePaths(5,8))