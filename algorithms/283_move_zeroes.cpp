class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==0) 
                {for (int j=i+1;j<nums.size();j++) {
                    if (nums[j]) {
                        nums[i]=nums[j];
                        nums[j]=0;
                        break;
                        }
                    }
                }
            }
        }
};
