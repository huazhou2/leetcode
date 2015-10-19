#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int> > nums(matrix.size(),vector<int>(matrix[0].size(),0));
        int max=0;
        for (int i=0;i<matrix.size();i++) 
            if (matrix[i][0]=='1') {
                nums[i][0]=1;
                max=1;}
        for (int i=0;i<matrix[0].size();i++)
            if (matrix[0][i]=='1') {
                nums[0][i]=1;
                max=1;}
        for (int i=1;i<matrix.size();i++)
            for (int j=1;j<matrix[0].size();j++) {
		if (matrix[i][j]=='1') {
                nums[i][j]=std::min(std::min(nums[i-1][j-1],nums[i-1][j]),nums[i][j-1])+1;
		cout<<i<<"\t"<<j<<"\t"<<nums[i][j]<<endl;
                if (nums[i][j]>max) max=nums[i][j];}}
        return max*max;
    }
};
int main() {
	char a[]={'1','0','1','0','0'};
	char b[]={'1','0','1','1','1'};
	char c[]={'1','1','1','1','1'};
	char d[]={'1','0','0','1','0'};
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
	cout<<m.maximalSquare(matrix)<<endl;
	}
