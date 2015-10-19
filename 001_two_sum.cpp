#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.empty()) return result;
        unordered_map<int,int> map;
	//store the elements to map,so the search takes O(logn) time
        for (int i=0;i<nums.size();i++) {
            map[nums[i]]=i+1;
        }
        int left=0, right=nums.size()-1;
        for (int i=0;i<nums.size();i++) {
            int temp=target-nums[i];
            if (map.find(temp)!=map.end() && map[temp]!=i+1) {
                result.push_back(i+1);
                result.push_back(map[temp]);
                break;
            }
        }
        return result;
    }
};
//Printer for vector element
void print (const vector<int> nums) {
	if (nums.empty()) return;
	for (int i=0;i<nums.size();i++) {
		if (i==nums.size()-1) 
			cout<<nums[i]<<endl;
		else 
			cout<<nums[i]<<"\t";
		}
	}
//Driver function
int main() {
	vector<int> nums={2,3,4};
	cout<<"Vector:\t" <<endl;
	print(nums);
	Solution m;
	vector<int> result=m.twoSum(nums,6);
	cout<<"Index is:\t";
	print(result);
	}
