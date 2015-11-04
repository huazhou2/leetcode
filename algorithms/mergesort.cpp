#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>& nums, int left, int right);
void mergeSort(vector<int>& nums,int left, int right) {
	if (left>=right) return;
	int mid=(left+right)/2;
	mergeSort(nums,left,mid);
	mergeSort(nums,mid+1,right);
	merge(nums,left,right);
	}
void merge(vector<int>& nums,int left,int right){
	int mid=(left+right)/2;
	vector<int> temp(right-left+1,0);
	int i=left;
	int j=mid+1;
	int k=0;
	int size=right-left+1;
	while (k<size) {
		if (i<=mid && (nums[i]<=nums[j] || j>right)) 
			temp[k++]=nums[i++];
		else 
			temp[k++]=nums[j++];
		}
	for (k=0;k<size;k++) 
		nums[left+k]=temp[k];
	}

void print(const vector<int>& nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) 
	if (i==nums.size()-1) 
		cout<<nums[i]<<endl;
	else 
		cout<<nums[i]<<"  ";
		}
int main() {
	int a[]={10,7,1,4,3,2,5};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	print(nums);
	mergeSort(nums,0,nums.size()-1);
	print(nums);
	}
	
		 
	
