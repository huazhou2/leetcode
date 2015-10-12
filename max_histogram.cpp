#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int result=0;
        if (height.empty()) return 0;
        stack<int> sta;
	height.push_back(0);
        sta.push(0);
        for (int i=1;i<height.size();i++)  {
            if (height[i]<height[sta.top()]) {
                while (!sta.empty()) {
                    int cur=height[sta.top()];
                    if (cur>height[i]) {
                        sta.pop();
			int max;
			if (sta.empty())	
			max=cur*i;
			else
                        max=cur*(i-sta.top()-1);
                        result=result>max?result:max;
                    }
                    else 
                        break;
                }}
            sta.push(i);
                    }
        return result;
    }
};

int main() {
	int a[]={4,2,0,3,2,5};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<"max area is :"<<endl;
	cout<<m.largestRectangleArea(nums)<<endl;}

