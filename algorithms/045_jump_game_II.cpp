class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums[0]==0) return 0;
        int cur=0;
        int start=-1;
        int end=0;
        if (nums.size()==1 && nums[0]) return 0;
        while (start!=end) {
            if (end>=nums.size()-1) return cur;
            cur++;
            int temp=end;
            for (int i=temp;i>start;i--) {
                if (i+nums[i]>end) end=i+nums[i];
            }
            start=temp;
       
        }
        return cur;}
};
