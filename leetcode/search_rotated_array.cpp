#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return binary(nums,0,nums.size()-1,target);
    }
    int binary(vector<int>& nums, int start, int end, int target) {
        if (start>end) return -1;
        if (nums[(start+end)/2]==target) return (start+end)/2;
        if (nums[(start+end)/2]>=nums[start]) {
            if (target>=nums[start] && target<nums[(start+end)/2]) return binary(nums,start,(start+end)/2-1,target);
            else return binary(nums,(start+end)/2+1,end,target);
        }
        else {
            if (target>nums[(start+end)/2] && target <= nums[end]) return binary(nums,(start+end)/2+1,end,target);
            else return binary(nums,start,(start+end)/2-1,target);
        }
    }
};

int main() {
	int a[]={4,5,6,7,0,1,2};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<m.search(nums,0)<<endl;
	}

