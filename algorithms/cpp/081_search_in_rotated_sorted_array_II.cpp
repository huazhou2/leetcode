class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        else return divide(nums,target,0, nums.size()-1);
    }
    int divide(vector<int>& nums, int target, int left, int right) {
        if (left>right)
            return false;
        int mid=(left+right)/2;
        if (target==nums[mid]) return true;
        if (nums[left]<nums[mid])  {
            if (target<=nums[mid] && target>=nums[left]) return divide(nums,target,left, mid-1);
            else return divide(nums,target,mid+1,right);
        }
        else if (nums[left]>nums[mid]) {
            if (target>nums[mid] && target<=nums[right]) return divide(nums,target, mid+1,right);
            else return divide(nums,target,left, mid-1);
        }
        else return divide(nums,target,left+1,right);
    }
};
