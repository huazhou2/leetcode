#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<2) return;
        int index=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]>nums[i-1]) index=i;
        }
        int index2=index-1;	
        for (int i=index;i<nums.size();i++) {
            if (nums[i]>nums[index-1]) index2=i;}
	cout<<"index1 "<<index<<" index2 " <<index2<<endl;
        if (index==0) swap(nums,0,nums.size()-1);
        else {
            int temp=nums[index-1];
            nums[index-1]=nums[index2];
            nums[index2]=temp;
            swap(nums,index,nums.size()-1);
        }
    }
    void swap(vector<int>& nums, int left, int right) {
        if (left>=right) return;
        for (int i=left;i<(right+left+1)/2;i++) {
            int temp=nums[i];
            nums[i]=nums[right-i+left];
            nums[right-i+left]=temp;
        }
    }
};

void print(const vector<int>& nums) {
	if (!nums.empty()) {
		for (int i=0;i<nums.size();i++) 
			cout<<nums[i]<<"  ";
		cout<<endl;
		}
	}
int main() {
	int a[]={5,4,7,5,3,2};
	Solution m;
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	cout<<"current permutation:"<<endl;
	print(nums);
	m.nextPermutation(nums);
	cout<<"next permutation:"<<endl;
	print(nums);
	}
	
