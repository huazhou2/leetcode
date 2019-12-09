class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        r,c=len(board),len(board[0])
        visited=[[False]*c for _ in range(r)]

        def helper(board,visited,word,step,i,j):
            if board[i][j] != word[step] or visited[i][j]:
                return False
            if step==len(word)-1:
                return True
            visited[i][j]=True
            for dx,dy in zip([1,0,-1,0],[0,1,0,-1]):
                nx,ny=i+dx,j+dy
                if 0<=nx<len(board) and 0<=ny<len(board[0]):
                    if helper(board,visited,word,step+1,nx,ny):
                        return True
            visited[i][j]=False
        for i in range(r):
            for j in range(c):
                if helper(board,visited,word,0,i,j):
                    return True
        return False

a=Solution()
board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

a.exist(board,'ABCCED')

