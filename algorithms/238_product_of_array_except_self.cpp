class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        result.push_back(1);
        int med=1;
        for (int i=0;i<nums.size()-1;i++) {
              med=med*nums[i];
              result.push_back(med);}
        med=1;
        for (int i=0;i<nums.size();i++) {
            result[nums.size()-1-i]=result[nums.size()-1-i]*med;
            med=nums[nums.size()-1-i]*med;
        }
        return result;
    }
};
