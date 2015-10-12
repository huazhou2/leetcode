#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        string temp1 = s1;
        string temp2 = s2;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1 != temp2) return false;//剪枝
        for(int i = 1;i < s1.size();i++){
            string s11 = s1.substr(0,i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0,i);
            string s22 = s2.substr(i);
            if(isScramble(s1.substr(0,i),s2.substr(0,i))&&isScramble(s1.substr(i),s2.substr(i))) return true;
            if(isScramble(s1.substr(0,i),s2.substr(s2.size()-i)) && isScramble(s1.substr(i),s2.substr(0,s2.size()-i))) return true;
         }
         return false;
    }
};
int main() {
	string s1("great"),s2("retga");
	Solution m;
	m.isScramble(s1,s2)? cout<<"yes"<<endl: cout<<"no"<<endl;
}
	

