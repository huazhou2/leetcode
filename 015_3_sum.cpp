class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;
    if (nums.size()<3) return result;
    sort(nums.begin(),nums.end());
     vector<int> temp; 
    for (int i=0;i<nums.size()-2;i++)  {
            if (nums[i]>0) break;
            int target=-nums[i];
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if (nums[j]+nums[k]==target){
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            temp.push_back(nums[k]);
            result.push_back(temp);
            j++;k--;
            temp.clear();
                while (j<k && nums[j]==nums[j-1]) j++;
                while (j<k && nums[k]==nums[k+1]) k--;
                }
            else if ((nums[j]+nums[k])<target) j++;
            else if ((nums[j]+nums[k])>target) k--;
        }
            while(nums[i]==nums[i+1]) i++;
            }
    return result;
    }
};
