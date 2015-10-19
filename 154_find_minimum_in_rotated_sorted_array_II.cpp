class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return -1;
        return divide(nums,0,nums.size()-1);
    }
    int divide(vector<int>& nums, int left, int right) {
        if (left==right) return nums[left];
        if (right-left==1) return std::min(nums[left],nums[right]);
        int mid=(left+right)/2;
        if (nums[left]<nums[right]) return nums[left];
        else if (nums[left]==nums[mid]) return divide(nums,left+1,right);

        else if (nums[left]<nums[mid])
            return divide(nums,mid+1,right);
        else
            return divide(nums,left,mid);
    }
};
