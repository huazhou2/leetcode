class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int i=0;i<board.size();i++) {
            vector<int> row (9,0);
            vector<int> col(9,0);
            vector<int> square(9,0);
            for (int j=0;j<board[0].size();j++) {
                if (board[i][j]!='.') 
                {
                    if (row[board[i][j]-'1']==0) row[board[i][j]-'1']=1;
                    else if (row[board[i][j]-'1']==1) return false;
                }
                if (board[j][i]!='.') {
                    if (col[board[j][i]-'1']==0) col[board[j][i]-'1']=1;
                    else if (col[board[j][i]-'1']==1) return false;
                }
                int row_idx=(i/3)*3+j/3;
                int col_idx=(i%3)*3+j%3;
                if (board[row_idx][col_idx]!='.') {
                    if (square[board[row_idx][col_idx]-'1']==0) square[board[row_idx][col_idx]-'1']=1;
                    else if (square[board[row_idx][col_idx]-'1']==1) return false;
                }
    }
        }
        return true;
    }
};
