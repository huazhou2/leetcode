#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.empty()) return 1;
        int siz=nums.size();
        for (int i=0;i<siz;i++) {
            while (nums[i]!=i+1) {
                if (nums[i]<=0 || nums[i]>siz ||nums[i]==nums[nums[i]-1]) break;
                int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;}
        }
        for (int i=0;i<siz;i++) 
            if (nums[i]!=i+1) return i+1;
	return siz+1;
    }
};

int main() {
	int a[]={-1,5,7,8,3,2,1};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<"Series:\t";
	for (int i=0;i<nums.size();i++) 
		cout<<nums[i]<<"  ";
	cout<<endl;
	cout<<"First missing:\t"<<m.firstMissingPositive(nums)<<endl;
	}
