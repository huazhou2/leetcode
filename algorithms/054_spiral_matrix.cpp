#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        int row=0, col=0,count=0,limit=matrix.size()*matrix[0].size();
        int direction=1;
        int i=0;
	int j=0-1;
	int col_limit=matrix[0].size();
        while (count<limit) {
            switch (direction) {
                case 1:
                if (matrix[0].size()-col-1-j>0) {j++;cout<<"here"<<endl;}
                else {
			cout<<"wrong"<<matrix[0].size()<<endl;
                    direction =2;
                    i++;
                    row++;}
                break;
                case 2:
                if (i<matrix.size()-row) i++;
                else {direction =3;
                        j--;
                        col++;}
                        break;
                break;
                case 3:
                if (j>=col) j--;
                else {direction =4;
                        i--;}
                        break;
                case 4:
                if (i>row) i--;
                else {
                    direction =1;
                    j++;}
                    break;
            }
	cout<<"i "<<i <<"  j  "<<j<<endl;
            result.push_back(matrix[i][j]);
            count++;
                }
            return result;
        }
};

void print(const vector<int>& result) {
	if (!result.empty()) {
	for (int i=0;i<result.size();i++)
		cout<< result[i]<<"  ";
	cout<<endl;}
}

int main() {
	int a[]={1,2,3};
	int b[]={4,5,6};
	int c[]={7,8,9};
	vector<int> a1(a,a+sizeof(a)/sizeof(int));
	vector<int> b1(b,b+sizeof(b)/sizeof(int));
	vector<int> c1(c,c+sizeof(c)/sizeof(int));
	vector<vector<int> > matrix;
	matrix.push_back(a1);
	matrix.push_back(b1);
	matrix.push_back(c1);
	Solution m;
	vector<int> result=m.spiralOrder(matrix);
	print(result);}
	
