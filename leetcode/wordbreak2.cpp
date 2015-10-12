#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> result;
        string path("");
        if (s.empty() || wordDict.empty()) return result;
        vector<int> possible(s.size(),1);
        dfs(s,wordDict,0,result,path,possible);
        return result;
    }
    void dfs(string s, unordered_set<string>& wordDict, int start, vector<string>& result, string& path, vector<int>& possible) {
        if (start==s.size()) result.push_back(path.substr(0,path.size()-1));
        for (int i=start;i<s.size();i++) {
            unordered_set<string>::iterator it=wordDict.find(s.substr(start,i-start+1));
            if (it!=wordDict.end() && possible[i]) {
                int prev=result.size();
                path=path+s.substr(start,i-start+1)+' ';
                dfs(s,wordDict,i+1,result,path,possible);
                if (result.size()==prev) possible[i]=0;
                path=path.substr(0,path.size()-i+start-2);
            }
        }
        return;
    }
};
void print(const vector<string>& result) {
	if (result.empty()) return;
	for (int i=0;i<result.size();i++) 
		cout<<result[i]<<endl;
}
int main() {
	unordered_set<string> wordDict;
	wordDict.insert("cat");
	wordDict.insert("cats");
	wordDict.insert("and");
	wordDict.insert("sand");
	wordDict.insert("dog");
	string s("catsanddog");
	Solution m;
	vector<string> result=m.wordBreak(s,wordDict);
	print(result);
	}
