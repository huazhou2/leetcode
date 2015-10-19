#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty()) return false;
        while (s[0]==' ') s.erase(0,1);
        while (s[s.size()-1]==' ') s.erase(s.size()-1,1);
        bool eflag=false, signflag=false, pointflag=false, reqnum=true, innumber=false;
        for (int i=0;i<s.size();i++) {
            switch (s[i]) {
                case '+': 
                    if (!reqnum) return false;
                    if (pointflag && !eflag) return false;
                    if (signflag) return false;
                    else signflag=true;
                    break;
                case '-':
                    if (!reqnum) return false;
                    if (pointflag && !eflag) return false;
                     if (signflag) return false;
                    else signflag=true;
                    break;
                case ' ':
                    if (innumber) return false;
                    else break;
                case '.':
                    if (pointflag) return false;
                    else pointflag=true;
                    break;
                case 'e':
                     if (reqnum) return false;
                    else reqnum=true;
                    if (eflag) return false;
                    else {
                        signflag=false;
                        eflag=true;
                        pointflag=true;
                    }
                    break;
                default:
                    if (s[i]-'0'>=0 && s[i]-'0'<=9) reqnum=false;
                    else return false;
                    break;
                    }
                innumber=true;
                     
            }
        return reqnum==false;
        }

};

int main() {
	Solution m;
	string s("2e10");
	string result=m.isNumber(s)? "yes":"no";
	cout<<s << endl<<result<<endl;
	}
