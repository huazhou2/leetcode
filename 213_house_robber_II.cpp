class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size()==1) return nums[0];
        return max( roblinear(nums,1,nums.size()-1), roblinear(nums,0,nums.size()-2));
        
    }
    int roblinear(vector<int>& nums, int start, int end) {
        if (end<start) return 0;
        if (end==start) return nums[start];
        vector<int> result;
        result.push_back(nums[start]);
        result.push_back(max(nums[start],nums[start+1]));
        for (int i=2;i+start<=end;i++) {
            result.push_back(max(result[i-2]+nums[start+i], result[i-1]));
        }
        return result.back();
    }
};
