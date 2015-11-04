class Solution {
public:
    string largestNumber(vector<int>& nums) {
    string result="";
    for (int i=0;i<nums.size()-1;i++) {
        for (int j=0;j<nums.size()-1-i;j++) {
            if (!larger(nums[j],nums[j+1])) {int temp=nums[j+1];nums[j+1]=nums[j];nums[j]=temp;}
        }
    }
    if (nums[0]==0) return "0";
    for (int i=0;i<nums.size();i++) {
        result=result+to_string(nums[i]);
    }
    return result;
    }
    
    bool larger(int a, int b) {
        if (a==b) return true;
        return ((to_string(a)+to_string(b))>(to_string(b)+to_string(a)));
        
    }
};
