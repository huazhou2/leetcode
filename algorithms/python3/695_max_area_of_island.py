class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        r,c=len(grid),len(grid[0])
        visited=[[False]*c for i in range(r)]

        def dfs(visited,i,j):
                if not(0<=i<r and 0<=j<c and not visited[i][j] and grid[i][j]):
                    return 0
                else:
                    visited[i][j]=True
                    return dfs(visited,i+1,j)+dfs(visited,i-1,j)+dfs(visited,i,j+1)+dfs(visited,i,j-1)+1

        ans=0
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    ans=max(ans,dfs(visited,i,j))
        return ans


    ###using iterative dfs, stack implemented as list

    def maxAreaOfIsland2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0
        r,c=len(grid),len(grid[0])
        visited=[[False]*c for i in range(r)]
        def dfs(grid,visited,i,j):
            nxt_steps=[(-1,0),(1,0),(0,-1),(0,1)]
            cnt=0
            stack=list()
            if grid[i][j] and not visited[i][j]:
                stack.append((i,j))
                visited[i][j]=True
            while stack:
                curi,curj=stack.pop()
                cnt+=1
                for k,m in nxt_steps:
                    nr=curi+k
                    nc=curj+m
                    if 0<=nr<r and 0<=nc<c and not visited[nr][nc] and grid[nr][nc]:
                        visited[nr][nc]=True
                        stack.append((nr,nc))
            return cnt
        ans=0
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    ans=max(dfs(grid,visited,i,j),ans)
        return ans


    ###using iterative bfs, queue implemented as deque

    def maxAreaOfIsland3(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque
        if not grid:
            return 0
        r,c=len(grid),len(grid[0])
        visited=[[False]*c for i in range(r)]
        def bfs(grid,visited,i,j):
            nxt_steps=[(-1,0),(1,0),(0,-1),(0,1)]
            cnt=0
            dq=deque()
            if grid[i][j] and not visited[i][j]:
                dq.append((i,j))
                visited[i][j]=True
            while dq:
                curi,curj=dq.popleft()
                cnt+=1
                for k,m in nxt_steps:
                    nr=curi+k
                    nc=curj+m
                    if 0<=nr<r and 0<=nc<c and not visited[nr][nc] and grid[nr][nc]:
                        visited[nr][nc]=True
                        dq.append((nr,nc))
            return cnt
        ans=0
        for i in range(r):
            for j in range(c):
                if grid[i][j]:
                    ans=max(ans,bfs(grid,visited,i,j))

        return ans







a1=Solution()
grid=[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]

print(a1.maxAreaOfIsland(grid))
print(a1.maxAreaOfIsland2(grid))
print(a1.maxAreaOfIsland3(grid))


