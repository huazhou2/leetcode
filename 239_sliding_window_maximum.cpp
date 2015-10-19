#include <iostream>
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.empty()) return result;
        deque<int> que;
	que.push_back(0);
        for (int i=1;i<nums.size();i++) {
            if (i-que.front()>=k) que.pop_front();
            for (deque<int>::iterator it=que.end()-1;it!=que.begin()-1;it--) 
                if (nums[i]>=nums[*it]) que.erase(it);
            que.push_back(i);
            if (i>=k-1) result.push_back(nums[que.front()]);
        }
        return result;}
};
void print(const vector<int>& nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) 
		if (i==nums.size()-1) 
			cout<<nums[i]<<endl;
		else 
			cout<<nums[i]<<"  ";
	}

int main() {
	int a[]={1,3,-1,-3,5,3,6,7};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution m;
	cout<<"Original Series:"<<endl;
	print(nums);
	vector<int> result=m.maxSlidingWindow(nums,3);
	cout<<"Max sliding window:"<<endl;
	print(result);	}	
