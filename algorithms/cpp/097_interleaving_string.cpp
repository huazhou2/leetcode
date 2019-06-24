#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int> > nums(s1.size()+1, vector<int> (s2.size()+1,0));
        if (s3.size() != s1.size()+s2.size()) return false;
        nums[0][0]=1;
        for (int i=0;i<s1.size();i++) {
            if (s3[i]==s1[i]) nums[i+1][0]=1;
            else break;
        }
        for (int i=0;i<s2.size();i++) {
            if (s3[i]==s2[i]) nums[0][i+1]=1;
            else break;
        }
        for (int i=1;i<=s1.size();i++) {
            for (int j=1;j<=s2.size();j++) {
               nums[i][j]= (nums[i-1][j] && s3[i+j-1]==s1[i-1]) || (nums[i][j-1] && s3[i+j-1]==s2[j-1]);
            }
        }
        return nums.back().back();
    }
};

int main() {
	string s1("aabcc");
	string s2("dbbca");
	string s3("aadbbbaccc");
	Solution m;
	m.isInterleave(s1,s2,s3)? cout<<"yes"<<endl:cout<<"no"<<endl;
	}
