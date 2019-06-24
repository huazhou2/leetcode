class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        for (int i=0;i<nums.size()/2;i++) {
            int temp=nums[i];
            nums[i]=nums[nums.size()-i-1];
            nums[nums.size()-i-1]=temp;
        }
        for (int i=0;i<k/2;i++){
            int temp=nums[i];
            nums[i]=nums[k-1-i];
            nums[k-1-i]=temp;}
        for (int i=k;i<((nums.size()-k)/2+k);i++) {
            int temp=nums[i];
            nums[i]=nums[nums.size()-i+k-1];
            nums[nums.size()-i+k-1]=temp;
        }
        
    }
};
