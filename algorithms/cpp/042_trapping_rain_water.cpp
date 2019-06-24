#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int cur=height[0];
        int total=0;
        int highest=0;
        int temp=0;
        int i=1;
        for (;i<height.size();i++) {
            if (height[i]<cur) temp+=(cur-height[i]);
            else {
                cur=height[i];
                highest=i;
                total+=temp;
                temp=0;}
        }
        cur=height.back();
        temp=0;
        for (int j=height.size()-1;j>=highest;j--) {
            if (height[j]<cur) temp+=(cur-height[j]);
            else {
                cur=height[j];
                total+=temp;
                temp=0;}
            }
        return total;
    }
};

int main() {
	int a[]={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<m.trap(nums)<<endl;
	}	
