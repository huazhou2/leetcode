#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1==s2) return true;
        vector<int> count(26,0);
        for (int i=0;i<s1.size();i++) {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for (int i=0;i<26;i++) 
            if (count[i]!=0) return false;
        for (int i=1;i<s1.size();i++) {
        bool result  = isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i));
        result  = result || (isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i)));
        if (result) return true;
        
        }
        return false;
    }
};
int main() {
	string s1("great"),s2("retga");
	Solution m;
	m.isScramble(s1,s2)? cout<<"yes"<<endl: cout<<"no"<<endl;
}
	

