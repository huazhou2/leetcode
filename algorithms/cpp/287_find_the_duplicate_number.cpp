class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return 0;
        for (int i=0;i<nums.size();i++) {
            while (nums[i]!=i+1) {
                if (nums[i]==nums[nums[i]-1]) return nums[i];
                int temp=nums[nums[i]-1];
                nums[nums[i]-1]=nums[i];
                nums[i]=temp;
            }
            }
        }
};
