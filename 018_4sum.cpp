class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size()<4) return result;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        for (int i=0;i<nums.size()-3;i++) {
            for (int j=i+1;j<nums.size()-2;j++) {
                int k=j+1;
                int l=nums.size()-1;
                int targe=target-nums[i]-nums[j];
                while(k<l) {
                if (nums[k]+nums[l]==targe) {
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    temp.push_back(nums[l]);
                    result.push_back(temp);
                    temp.clear();
                    k++;
                    l--;
                    while(nums[k]==nums[k-1] && k < l) k++;
                    while(nums[l]==nums[l+1] && l > k) l--;
                }
                else if (nums[k]+nums[l]<targe) k++;
                else if (nums[k]+nums[l]>targe) l--;
                }
                while(nums[j]==nums[j+1]) j++;
                }
                while(nums[i]==nums[i+1]) i++;
                }
        return result;
}
};
