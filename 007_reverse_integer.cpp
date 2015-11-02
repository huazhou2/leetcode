#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int nega=1;
        if (x<0) {
            x=-x;
            nega=-1;}
        if (x==0) return x;
        vector<int> digits;
        while(x>0){
            digits.push_back(x%10);
            x=x/10;
        }
        int result=0;
        for (vector<int>::iterator it=digits.begin();it!= digits.end(); it++){
            result+= *it*pow(10,digits.end()-it-1);
        }
        if (result<0)
        result=0;
        return result*nega;
        }
};

int main() {
	int num=2030;
	Solution m;
	cout<<"num:  "<<num<<"   reverse:  "<<m.reverse(num)<<endl;
	}
	
