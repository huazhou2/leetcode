#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum=0,right=-1;
        for (int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if (sum>=s) {
                right=i;
                break;}
        }
        if (right==-1) return 0;
        int min=right+1;
        int left=0;
        sum-=nums[right];
        for (int i=right;i<nums.size();i++) {
            sum+=nums[i];
            for (;left<i;left++) {
                if ((sum-nums[left])<s) break;
                sum-=nums[left];
            }
            if (i-left+1<min) min=i-left+1;
        }
        return min;
    }
};
int main() {
	int a[]={2,4,1,5,7,6,1,4,9,2,3};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<m.minSubArrayLen(15,nums)<<endl;
	}
