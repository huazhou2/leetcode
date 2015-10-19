#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	if (nums.size()<=2) return nums.size(); 
        int left=1;
        int count=1, value=nums[0];
        for (int i=1;i<nums.size();i++) {
            if (nums[i]==value) {
                count++; 
                if (count<=2) {swap(nums,left,i);left++;}}
            else {
                value=nums[i];
                count=1;
                swap(nums,left,i);
                left++;
            }
        }
        return left;
    }
    void swap(vector<int>& nums, int left, int right) {
        if (left==right) return;
        int temp=nums[left];
        nums[left]=nums[right];
        nums[right]=temp;
    }
};
   void print(const vector<int>& nums) {
 	if (!nums.empty()) {
		for (int i=0;i<nums.size();i++) 
			cout<<nums[i]<<"  ";
		cout<<endl;
		}
	}

int main () {
	int a[]={1,1,1,2,2,2,2,3,3,5};
	vector<int> nums(a, a+sizeof(a)/sizeof(int));
	print(nums);
	Solution m;
	cout<<"left over:  "<<m.removeDuplicates(nums)<<endl;
	print(nums);
	}
