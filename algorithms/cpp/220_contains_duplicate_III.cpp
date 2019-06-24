class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k<1 || t<0) return false;
        map<int, int> window;
        int start=0;
        for (int cur=0;cur<nums.size();cur++) {
            if (cur-start>k) 
                if (window[nums[start]]==start) window.erase(nums[start++]);
        map<int, int>::iterator it=window.lower_bound(nums[cur]-t);
        if (it != window.end() && abs(it->first-nums[cur])<=t) return true;
        window[nums[cur]]=cur;
        }
        return false;
        }
};
