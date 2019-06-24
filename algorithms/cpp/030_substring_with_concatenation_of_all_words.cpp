#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;
        unordered_map<string,int> map;
        for (int i=0;i<words.size();i++) 
            map[words[i]]=0;
        for (int i=0;i<words.size();i++)
            map[words[i]]++;
        int length=s.size()-words.size()*words[0].size();
        for (int i=0;i<=length;i++) {
		cout<<i<<endl;
            if (isSubstring(s,i,words[0].size(),words.size(),map))
                result.push_back(i);
        }
        return result;
    }
    bool isSubstring(string& s, int start,int size, int count, unordered_map<string,int> map) {
        int cnt=0;
        for (int i=start;;i+=size) {
            unordered_map<string,int>::iterator it=map.find(s.substr(i,size));
            if (it==map.end()) return false;
            else {
                it->second--;
                cnt++;
                if (it->second<0) return false;
                if (count==cnt) return true;}
            }
        }
};

int main() {
	string s("wordgoodgoodgoodbestword");
	vector<string> words;
	words.push_back("word");
	words.push_back("good");
	words.push_back("best");
	words.push_back("good");
	Solution m;
	vector<int> result=m.findSubstring(s,words);
	for (int i=0;i<result.size();i++) 
		cout<<result[i]<<"\t";
	cout<<endl;}
