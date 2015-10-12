#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        int start=0,end=-1;
        unordered_map<char,int> freq;
        for (int i=0;i<t.size();i++) {
            unordered_map<char,int>::iterator it=freq.find(t[i]);
            if (it==freq.end()) freq[t[i]]=0;
            else it->second--;
        }
        int count=0;
        vector<int> seq;
        for (int i=0;i<s.size();i++) {
            unordered_map<char,int>::iterator it=freq.find(s[i]);
            if (it!=freq.end()) {
                seq.push_back(i);
                it->second++;
                if (it->second==1) count++;
                if (count==freq.size()) {
                    end=i;break;}
            }
        }
     if (end==-1) return "";
     for (int i=end+1;i<s.size();i++) {
         unordered_map<char,int>::iterator it=freq.find(s[i]);
         if (it!=freq.end()) seq.push_back(i); 
     }
     int min=s.size();
     int start_i,end_i;
     for (int i=0;i<seq.size();i++) {
         start=seq[i];
         int tem_min=end-start+1;
         if (tem_min<=min) {
                start_i=start;
                end_i=end;
                min=tem_min;
                }
         int temp=--freq[s[start]];
         if (temp==0) {
                end=next(s[start],s,end);
                if (end==-1) break;
                freq[s[start]]++;
         }
     }
    return s.substr(start_i,end_i-start_i+1);
     }
     
     int next(char a, string& s, int start) {
         for (int i=start+1;i<s.size();i++) 
             if (s[i]==a) return i;
         return -1;
         }
};
int main() {
	string s("ADOBECODEBANC");
	string t("ABC");
	Solution m;
	cout<<s<<endl;
	cout<<t<<endl;
	cout<<m.minWindow(s,t)<<endl;
	}
