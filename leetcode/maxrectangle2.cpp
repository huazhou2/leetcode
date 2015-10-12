#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int max=0;
        for (int i=0;i<matrix.size();i++) {
            vector<int> height(matrix[0].size(),0);
            for (int j=0;j<matrix[0].size();j++) {
                for (int k=i;k>=0;k--) 
                    if (matrix[k][j]=='1') height[j]++;
                    else break;
                }
        int row_max=maxHistogram(height);
	cout<<i+1<<"  "<<row_max<<endl;
        max=max>row_max? max: row_max;
        }
        return max;
    }
    int maxHistogram (vector<int>& height) {
        int result=0;
        if (height.empty()) return 0;
        height.push_back(0);
        stack<int> sta;
        sta.push(0);
       for (int i=1;i<height.size();i++) {
            if (height[sta.top()]>height[i]) {
                while (!sta.empty()) {
                    int cur=height[sta.top()];
                    if (cur>height[i]) {
                        sta.pop();
                        int max;
                        if (sta.empty())
                            max=cur*i;
                        else 
                            max=cur*(i-sta.top()-1);
                        result=result>max?result:max;
                    }
                    else break;
                }
                }
            sta.push(i);
            }
        return result;
    }
};

int main() {
	char a[]={'1','1','1','0','1'};
	char b[]={'1','1','0','1','0'};
	char c[]={'0','1','1','1','0'};
	char d[]={'1','1','1','1','0'};
	char e[]={'1','1','1','1','1'};
	char f[]={'0','0','0','0','0'};
	vector<char> a1(a,a+sizeof(a)/sizeof(char));
	vector<char> b1(b,b+sizeof(b)/sizeof(char));
	vector<char> c1(c,c+sizeof(c)/sizeof(char));
	vector<char> d1(d,d+sizeof(d)/sizeof(char));
	vector<char> e1(e,e+sizeof(e)/sizeof(char));
	vector<char> f1(f,f+sizeof(f)/sizeof(char));
	vector<vector<char> > matrix;
	matrix.push_back(a1);
	matrix.push_back(b1);
	matrix.push_back(c1);
	matrix.push_back(d1);
	matrix.push_back(e1);
	matrix.push_back(f1);
	Solution m;
	cout<<m.maximalRectangle(matrix)<<endl;}
		

