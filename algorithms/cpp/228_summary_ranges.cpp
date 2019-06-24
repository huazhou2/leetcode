class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.size()==0) return result;
        if (nums.size()==1) {result.push_back(to_string(nums[0]));return result;}
        int start=nums[0],end;
        for (int i=1;i<nums.size();i++ ) {
                if (nums[i]-nums[i-1]!=1) {
                    end=nums[i-1];
                    if (start==end) 
                    result.push_back(to_string(start));
                    else result.push_back(to_string(start)+ "->" + to_string(end));
                    start=nums[i];
                }
                
            }
            end=nums.back();
             if (start==end) 
                    result.push_back(to_string(start));
                    else result.push_back(to_string(start)+ "->" + to_string(end));
                    return result;
                
            }
};
