#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void print(const vector<vector<char> >& board);
class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i=0;i<board.size();i++) {
            if (board[i][0]=='O') bfs(board,i,0);
            if (board[i][board[0].size()-1]=='O') bfs(board,i,board[0].size()-1);
        }
        for (int i=0;i<board[0].size();i++) {
            if (board[0][i]=='O') bfs(board,0,i);
            if (board[board.size()-1][i]=='O') bfs(board,board.size()-1,i);
        }
        for (int i=0;i<board.size();i++) 
            for (int j=0;j<board[0].size();j++) 
                if (board[i][j]=='1') board[i][j]='O';
                else if (board[i][j]=='O') board[i][j]='X';
    }
    void bfs(vector<vector<char> >& board, int row, int col) {
        queue<pair<int,int> > que;
        board[row][col]='1';
        que.push(std::make_pair(row,col));
        while (!que.empty()) {
            std::pair<int,int> temp=que.front();
            row=temp.first;
            col=temp.second;
            que.pop();
            if (row-1>=0 && board[row-1][col]=='O') {
                board[row-1][col]='1';
                que.push(std::make_pair(row-1,col));}
            if (row+1<board.size() && board[row+1][col]=='O') {
                board[row+1][col]='1';
                que.push(std::make_pair(row+1,col));}
            if (col-1>=0 && board[row][col-1]=='O') {
                board[row][col-1]='1';
                que.push(std::make_pair(row,col-1));}
            if (col+1<board[0].size() && board[row][col+1]=='O') {
                board[row][col+1]='1';
                que.push(std::make_pair(row,col+1));}
        }
    }
};
	void print(const vector<vector<char> >& board) {
	if (board.empty() || board[0].empty()) return;
	for (int i=0;i<board.size();i++) {
		for (int j=0;j<board[0].size();j++)
			cout<<board[i][j]<<' ';
		cout<<endl;}
	}
int main() {
	char a[]={'O','O','O'};
	char b[]={'O','O','O'};
	char c[]={'X','X','O'};
	vector<char> a1(a,a+sizeof(a)/sizeof(char));
	vector<char> b1(b,b+sizeof(b)/sizeof(char));
	vector<char> c1(c,c+sizeof(c)/sizeof(char));
	vector<vector<char> > board;
	board.push_back(a1);
	board.push_back(b1);
	board.push_back(c1);
	cout<<"Before:"<<endl;
	print(board);
	Solution m;
	m.solve(board);
	cout<<"After:"<<endl;
	print(board);
	}
	

	
