#include <vector>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int minCut(string s) {
	if (s.empty()) return 0;
        vector<int> cut;
        int length=s.size();
        for (int i=0;i<=length;i++)
            cut.push_back(i-1);
        for (int i=0;i<length;i++) {
            for (int j=0;i+j<length && i-j>=0 && s[i+j]==s[i-j];j++) 
                cut[i+j]=min(cut[i+j], 1+ cut[i-j]);
            for (int j=0;i+j+1<length && i-j>=0 && s[i+j+1]==s[i-j];j++)
		cut[i+j]=min(cut[i+j], 1+ cut[i-j]);
        }
        return cut.back();
        }
};

int main() {
	string s("aab");
	cout<<s<<endl;
	Solution m;
	cout<<"min cut: "<<m.minCut(s)<<endl;
	}
