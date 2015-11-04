class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        if (nums.size()<2) return result;
        int dif_or=0;
        for (int i=0;i<nums.size();i++) 
            dif_or ^= nums[i];
        int lowbit=dif_or & (-dif_or);
        int num1=0,num2=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i] & lowbit) num1 ^= nums[i];
            else num2^=nums[i];
        }
        result.push_back(num1);
        result.push_back(num2);
        return result;
    }
};
