#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        int s1=word1.size()+1;
        int s2=word2.size()+1;
        vector<vector<int> > mat(s1,vector<int>(s2,0));
        for (int i=1;i<mat.size();i++) 
            mat[i][0]=i;
        for (int i=1;i<mat[0].size();i++)
            mat[0][i]=i;
        for (int i=1;i<mat.size();i++) {
            for (int j=1;j<mat[i].size();j++) {
                if (word1[i-1]==word2[j-1])
                    mat[i][j]=mat[i-1][j-1];
                else
                    mat[i][j]=min(min(mat[i-1][j-1], mat[i-1][j]), mat[i][j-1])+1;
            }
        }
        return mat[s1-1][s2-1];
            }
};
int main() {
	string a("hua"),b("zhuattt");
	Solution m;
	cout<<m.minDistance(a,b)<<endl;
		}
