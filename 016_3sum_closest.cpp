class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int sum=nums[0]+nums[1]+nums[2];
        int min=sum-target;
        for (int i=0;i<nums.size()-2;i++) {
            int j=i+1, k=nums.size()-1;
            int tar=target-nums[i];
            while (j<k) {
            if (nums[j]+nums[k]-tar==0) return (nums[i]+nums[j]+nums[k]);
            if (abs(min)>abs(nums[j]+nums[k]-tar)) {min=nums[j]+nums[k]-tar; sum=nums[i]+nums[j]+nums[k];}
            if (nums[j]+nums[k]-tar>0) {
                k--;}
            else if (nums[j]+nums[k]-tar<0) {
                j++;}
            while(nums[k]==nums[k+1]) k--;
            while(nums[j]==nums[j-1]) j++;
            }
            while(nums[i]==nums[i+1]) i++;
            }
        return sum;
        }
};
