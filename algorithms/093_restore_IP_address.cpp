#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string path="";
        dfs(s,0,0,path,result);
        return result;
    }
    void dfs(string s, int start, int deep, string& path, vector<string>& result) {
 
        if (s.size()-start>3*(4-deep)) return;
        if (deep==4) result.push_back(path);
        for (int i=start;i<start+3;i++) {
            if (i>s.size()-1) return;
            if (!isCorrect(s,start,i)) continue;
            path=path+s.substr(start,i-start+1);
            path=deep==3?path:path+".";
            dfs(s,i+1,deep+1,path,result);
            path.erase(start+deep);
        }
        return;
    }
    bool isCorrect(string& s, int start, int end) {
        if (s[start]=='0') return end==start;
        int result=0;
        for (int i=start;i<=end;i++) 
            result=10*result+s[i]-'0';
        return result<256;
        }
};

void print(const vector<string>& result) {
	if (!result.empty()) {
	for (int i=0;i<result.size();i++) 
		cout<<result[i]<<endl;
	}
	}
int main() {
	string s="1111111135";
	Solution m;
	cout<<"Raw string:"<<endl<<s<<endl;
	vector<string> result=m.restoreIpAddresses(s);
	print(result);
	}
