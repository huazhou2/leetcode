class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2) return 0;
        if (nums.size()==2) return nums[0]-nums[1]>0? nums[0]-nums[1]:nums[1]-nums[0];
        int min_num=std::numeric_limits<int>::max();
        int max_num=std::numeric_limits<int>::min();
        for (int i=0;i<nums.size();i++) {
            if (nums[i]<min_num) min_num=nums[i];
            if (nums[i]>max_num) max_num=nums[i];
        }
        
        float bucket_size=(max_num-min_num)/(nums.size()-1+0.0);
        vector<int> min_vec(nums.size()-1,0);
        vector<int> max_vec(nums.size()-1,0);
        min_vec.back()=max_num;
        max_vec.back()=max_num;
        for ( int i=0;i<nums.size();i++) {
            if (nums[i]==max_num) continue;
            int bucket_num = static_cast<int> ((nums[i]-min_num)/bucket_size);
            if (min_vec[bucket_num]==0 || min_vec[bucket_num]>nums[i]) min_vec[bucket_num]=nums[i];
            if (max_vec[bucket_num]==0 || max_vec[bucket_num]<nums[i]) max_vec[bucket_num]=nums[i];
        }
        int max_diff=0;
        for (int i=0;i<max_vec.size()-1;) {
            int start=max_vec[i];
            i++;
            while (min_vec[i]==0) i++;
            int diff=min_vec[i]-start;
            if (max_diff<diff) max_diff=diff;
        }
        return max_diff;
        }
};
