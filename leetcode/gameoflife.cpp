#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        for (int i=0;i<board.size();i++) {
            for (int j=0;j<board[0].size();j++) {
                if (sumSquare(board,i,j)==3) {
                    if (board[i][j]==1) board[i][j]=1;
                        else board[i][j]=2;}
                else if (sumSquare(board,i,j)==4) continue;
                else {if (board[i][j]==0)board[i][j]=0;
                        else board[i][j]=3;}
            }
        }
        for (int i=0;i<board.size();i++) 
            for (int j=0;j<board[0].size();j++) 
                if (board[i][j]==2) board[i][j]=1;
                else if (board[i][j]==3) board[i][j]=0;
    }
    int sumSquare(vector<vector<int> >& board, int row, int col) {
        int sum=0;
        int top=row>0? row-1:0;
        int left=col>0?col-1:0; 
        for (int i=top;i<=row+1 && i<board.size();i++) 
            for (int j=left;j<=col+1 && j<board[0].size();j++)
                {int cur=board[i][j];
                 if (cur%2) cur=1;
                 else cur=0;
                sum+=cur;}
        return sum;
        }
};

int main() {
	vector<vector<int> > board(1,vector<int>(1,1));
	Solution m;
	m.gameOfLife(board);
	}
