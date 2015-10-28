class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> result;
        for (int i=0;i<nums.size();i++) {
            auto map_it=result.find(nums[i]);
            if (map_it!=result.end())  
            result[nums[i]]+=1;
            else
            result[nums[i]]=1;
            if (result[nums[i]]>nums.size()/2)
            {return nums[i];
            break;}

        }
    }
};
