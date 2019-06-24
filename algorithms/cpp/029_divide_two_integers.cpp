#include <iostream>
#include <limits>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return 0;
        bool sign=dividend>0 ^ divisor>0;
        unsigned long newdividend, newdivisor;
        if (dividend<0) 
            newdividend=static_cast<unsigned long> (-(dividend+1))+1;
        else 
            newdividend=static_cast<unsigned long> (dividend);
        if (divisor<0) 
            newdivisor=static_cast<unsigned long> (-(divisor+1))+1;
        else
            newdivisor=static_cast<unsigned long> (divisor);
        int rem=0, div=0;
        for (int i=31;i>=0;i--) {
                rem<<=1;
                rem|=(newdividend>>i & 1);
                if (rem>=newdivisor){
                rem-=newdivisor;
                div |= (1<<i);
        }
        }
        int result;
        if (static_cast<int> (div) <0 ) 
            result=sign? static_cast<int> (div): static_cast<int> (div-1); 
        else 
        result=sign? (-div):div;
        return result;
    }
};

int main() {
	Solution m;
	while (true) {
	cout<<"Input number 1: ";
	int a,b;
	cin>>a;
	cout<<"Input number 1: ";
	cin>>b;
	cout<<m.divide(a,b)<<endl;
	}
	}

