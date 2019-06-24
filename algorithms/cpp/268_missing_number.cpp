class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int diff=0;
        for (int i=0;i<nums.size();i++) 
            diff+=(nums[i]-i);
        return nums.size()-diff;
        }
};
