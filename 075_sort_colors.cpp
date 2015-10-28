class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        while (left<right) {
            while (nums[left]<2 && left <= right) left++;
            while (nums[right]==2 && left <= right) right--;
            if (left < right) {swap(nums, left, right);
            left++;
            right--;}
        }
        left=0;
        while (left < right ) {
            while (nums[left]==0 && left <= right) left++;
            while (nums[right]>=1 && left<=right) right--;
            if (left<right) {swap (nums, left, right);
            left++;
            right--;}
        }
        
    }
    void swap (vector<int>& nums, int left, int right) {
        int temp=nums[right];
        nums[right]=nums[left];
        nums[left]=temp;
    }
};
