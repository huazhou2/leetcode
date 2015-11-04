#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result("");
        char dict[]={'M','D','C','L','X','V','I'};
        int digit[]={1000,500,100,50,10,5,1};
    for (int i=0; i<7;i++) {
        if (i%2) continue;
        int div=num/digit[i];
	num=num%digit[i];
        if (!div) continue;
        if (div<=3) result.append(div,dict[i]);
        else if (div==4) 
            result=result+dict[i]+dict[i-1];
        else if (div>=5 && div<=8)
            {result+=dict[i-1];
            result.append(div-5,dict[i]);}
        else result=result+dict[i]+dict[i-2];
    }
    return result;
    }
};

int main() {
	//this tests my code 
	int num;
	Solution m;
	while (true) {
	cout<<"Input an integer from 1 to 3999:\t";
	cin>>num;
	string result= m.intToRoman(num);
	cout<<"Roman Number is : "<<result<<endl;
	}
	}
	
