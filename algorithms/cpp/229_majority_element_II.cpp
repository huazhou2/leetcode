class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    int n1,n2;
    int c1=0,c2=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==n1) c1++;
            else if (nums[i]==n2) c2++;
            else if (!c1) {n1=nums[i];c1++;}
            else if (!c2) {n2=nums[i];c2++;}
            else {c1--;c2--;}
        }
        c1=0;c2=0;
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==n1) c1++;
            else if (nums[i]==n2) c2++;
        }
        vector<int> result;
        if (c1>nums.size()/3) result.push_back(n1);
        if (c2>nums.size()/3) result.push_back(n2);
        return result;
            
    }
};
