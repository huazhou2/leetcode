class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()<2) return nums.size();
        unordered_set<int> myset;
        for (int i=0;i<nums.size();i++) 
            myset.insert(nums[i]);
        int max_size=0;
        while (myset.size()>max_size) {
            unordered_set<int>::iterator it=myset.begin();
            int temp_max=0;
            int temp=*it+1;
            while (myset.find(temp)!=myset.end()) {
                myset.erase(temp); 
                temp++;
                temp_max++;}
            temp=*it;
            while (myset.find(temp)!=myset.end()) {
                myset.erase(temp);
                temp--;
                temp_max++;}
        max_size=max_size>temp_max?max_size:temp_max;
            }
        return max_size;
        }
};
