from typing import List
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        seen=[[False]*n for _ in range(n)]
        dr=[0,1,0,-1]
        dc=[1,0,-1,0]
        c=r=di=0
        ans=[[None]*n for _ in range(n)]
        for i in range(n*n):
            ans[r][c]=i+1
            cr,cc=r+dr[di],c+dc[di]
            seen[r][c]=True
            if 0<=cr<n and 0<=cc<n and not seen[cr][cc]:
                r,c=cr,cc
            else:
                di=(di+1) % 4
                r,c=r+dr[di],c+dc[di]
        return ans

a=Solution()

print(a.generateMatrix(4))
