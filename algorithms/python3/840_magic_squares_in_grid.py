class Solution(object):
    def numMagicSquaresInside(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        def isMagic(a,b,c,d,e,f,g,h,i):
            return sorted([a,b,c,d,e,f,g,h,i])==list(range(1,10)) and a+b+c==d+e+f==g+h+i==a+d+g==b+e+h==c+f+i==a+e+i==c+e+g==15

        ans=0
        r,c=len(grid),len(grid[0])
        for i in range(r-2):
            for j in range(c-2):
                if isMagic(grid[i][j],grid[i][j+1],grid[i][j+2],grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2],grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]):
                    ans+=1
        return ans

s=Solution()

grid=[[4,3,8,4],
        [9,5,1,9],
        [2,7,6,2]]
print(s.numMagicSquaresInside(grid))


