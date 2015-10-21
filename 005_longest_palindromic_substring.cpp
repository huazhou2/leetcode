#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        for (int i=s.size();i>=0;i--) s.insert(i,"*");
        int max=0,lhs=0,rhs=0;
        for (int i=0;i<s.size();i++) {
            int left=i-1,right=i+1;
            int count=0;
            if (s[i]!='*') count=1;
            while (left>=0 && right<s.size() && s[left] == s[right])  {
                if (s[left]!='*') count+=2;
                left--;
                right++;
                 }
        if (max<=count) {
            lhs=left+1;
            rhs=right-1;
            max=count;}
        }
        string result("");
        for (int i=lhs;i<=rhs;i++) 
            if (s[i]!='*') result=result+s[i];
        return result;
    }
};

int main(){
	string s("bb");
	Solution m;
	m.longestPalindrome(s);
	}
