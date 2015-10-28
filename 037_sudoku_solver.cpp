ass Solution {
public:
    bool solveSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j]=='.') {
                    for (int k=1;k<10;k++) {
                        char target='0'+k;
                        board[i][j]=target;
                        if (isvalid(board,i,j) && solveSudoku(board)) 
                            return true;
                        board[i][j]='.';
                        }
                    return false;
                    }
                } 
            }
        return true;
    }

    bool isvalid(const vector<vector<char>>& board, int row, int col) {
        char target=board[row][col];
        for (int i=0;i<9;i++) {
                if (i!=col) 
                    if (board[row][i] == target) return false;
        }
        for (int i=0;i<9;i++) {
                if (i!=row) 
                    if (board[i][col] == target) return false;
        }
        int row_num=row/3*3;
        int col_num=col/3*3;
        for (int i=0;i<9;i++) 
            if (row_num+i/3!=row && col_num+i%3!=col)
                if (board[row_num+i/3][col_num+i%3] == target) return false; 
        return true;
    }
};
