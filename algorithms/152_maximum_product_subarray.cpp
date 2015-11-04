class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int min_product=nums[0],max_product=nums[0], maximum=nums[0];
        for (int i=1;i<nums.size();i++) {
            int t1=min(min_product*nums[i], max_product*nums[i]);
            int t2=max(min_product*nums[i], max_product*nums[i]);
            min_product=min(t1,nums[i]);
            max_product=max(t2,nums[i]);
            maximum=maximum>max_product? maximum:max_product;
        }
        return maximum;
    }
};
