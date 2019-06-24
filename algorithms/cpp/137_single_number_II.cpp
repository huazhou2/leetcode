class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bit[32]={0};
        for (int i=0;i<nums.size();i++) {
            int number=nums[i];
            for (int j=0;j<32;j++) {
                bit[j]+=number & 1;
                number>>=1;}
        }
        int result=0;
        for (int i=0;i<32;i++) {
            result= result | (bit[i]%3) <<i;
        }
        return result;
            }
};
