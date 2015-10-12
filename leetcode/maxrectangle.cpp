#include <iostream>
#include <vector>
#include <limits>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int max=0;
        for (int i=0;i<matrix.size();i++) {
            for (int j=0;j<matrix.size();j++) {
                if (matrix[i][j]=='1') {
                    int temp=maxCur(matrix,i,j);
                    max=max>temp?max:temp;
                }
            }
        }
        return max;
    }
    int maxCur(vector<vector<char> >& matrix, int row,int col) {
        int max=0;
        int extention=std::numeric_limits<int>::max();
        for (int i=row;i<matrix.size();i++) {
            if (matrix[i][col]=='1') {
                int count=1;
                for (int j=col+1;j<matrix[0].size();j++)
                    if (matrix[i][j]=='1') count++;
                    else break;
                	extention=min(count,extention);
                        max=extention*(i-row+1)>max? extention*(i-row+1):max;
                    }
            else break;}
        return max;
    }
};

int main() {
	char a[]={'1','0','1','0','1'};
	char b[]={'1','0','1','0','1'};
	char c[]={'1','0','1','1','1'};
	char d[]={'1','0','1','1','1'};
	vector<char> a1(a,a+sizeof(a)/sizeof(char));
	vector<char> b1(b,b+sizeof(b)/sizeof(char));
	vector<char> c1(c,c+sizeof(c)/sizeof(char));
	vector<char> d1(d,d+sizeof(d)/sizeof(char));
	vector<vector<char> > matrix;
	matrix.push_back(a1);
	matrix.push_back(b1);
	matrix.push_back(c1);
	matrix.push_back(d1);
	Solution m;
	cout<<m.maximalRectangle(matrix)<<endl;}
		

