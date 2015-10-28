class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size()<2) return 0;
        int i=1;
        for (;i<nums.size()-1;i++) {
            if (nums[i]>nums[i+1] && nums[i]>nums[i-1]) return i;
        }
        if (i==nums.size()-1) {
            if (nums.back()>nums[nums.size()-2]) return nums.size()-1;
        }
        return 0;
    }
};
