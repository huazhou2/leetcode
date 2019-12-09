class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
        r,c=len(board),len(board[0])
        todo=False
        for i in range(r):
            for j in range(c-2):
                if abs(board[i][j])==abs(board[i][j+1])==abs(board[i][j+2])!=0:
                    board[i][j]=board[i][j+1]=board[i][j+2]=-abs(board[i][j])
                    todo=True
        for i in range(r-2):
            for j in range(c):
                if abs(board[i][j])==abs(board[i+1][j])==abs(board[i+2][j])!=0:
                    board[i][j]=board[i+1][j]=board[i+2][j]=-abs(board[i][j])
                    todo=True

        for i in range(c):
            cur=r-1
            for j in range(r-1,-1,-1):
                if board[j][i]>0:
                    board[cur][i]=board[j][i]
                    cur-=1
            for j in range(cur+1):
                board[j][i]=0

        if todo:
            return self.candyCrush(board)
        else:
            return board






a=Solution()

board=[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
newboard=a.candyCrush(board)
for i in range(len(board)):
    print(board[i])

for i in range(len(newboard)):
    print(newboard[i])
