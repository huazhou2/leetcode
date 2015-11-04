class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size()<2) return true;
        int cur=0;
        for (int i=0;i<nums.size();i++) {
            int index=nums.size()-1-i;
            if (nums[index]>=i-cur) cur=i;
        }
        return cur==nums.size()-1;
    }
};
