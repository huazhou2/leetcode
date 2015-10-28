class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || word.empty() || board[0].empty()) return false;
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                if (board[i][j]==word[0]) {
                    vector<bool> visited(board.size()*board[0].size(),false);
                    if (dfs(board,word, visited, i,j, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char> >& board, string& word, vector<bool>& visited, int row,int col, int deep) {
        if (deep==word.size()-1 && board[row][col]==word[deep]) return true;
        if (board[row][col]==word[deep]) {
            visited[row*board[0].size()+col]=true;
            if (row>0 && visited[(row-1)*board[0].size()+col]==false && dfs(board,word,visited,row-1,col,deep+1)) return true;
            if (row<board.size()-1 && visited[(row+1)*board[0].size()+col]==false && dfs(board,word,visited,row+1,col,deep+1)) return true;
            if (col>0 && visited[row*board[0].size()+col-1]==false && dfs(board,word,visited,row, col-1,deep+1)) return true;
            if (col<board[0].size()-1 && visited[row*board[0].size()+col+1]==false && dfs(board,word,visited,row,col+1,deep+1)) return true;
            visited[row*board[0].size()+col]=false;
            return false;
        }
      else return false;
    }
};
