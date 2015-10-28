class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        float left=target-0.1, right=target+0.1;
        int l_pos=binarySearch(nums,0,nums.size()-1,left);
        int r_pos=binarySearch(nums,0,nums.size()-1,right);
        l_pos+=1;
        vector<int> result(2,-1);
        if (l_pos<=r_pos) {
            result[0]=l_pos;
            result[1]=r_pos;
        }
        return result;
    }
    int binarySearch(vector<int>& nums, int left, int right, float target) {
        if (left>right) return right;
        int mid=(left+right)/2;
        if (nums[mid]>target) return binarySearch(nums,left,mid-1,target);
        else return binarySearch(nums,mid+1,right,target);
    }
};
