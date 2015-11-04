#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        if (s.empty()) {
            if (p[1]=='*') return isMatch(s,p.substr(2));
            else return false;
        }
        if (p[1]!='*') {
            if (s[0]==p[0] || p[0]=='.') return isMatch(s.substr(1),p.substr(1));
            else return false;}
        else { if (isMatch(s,p.substr(2))) return true;
            else if (s[0]==p[0] || p[0]=='.') return  isMatch(s.substr(1),p) ;}
    }
};
