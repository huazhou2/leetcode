class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int,int> m;
        for (auto it=nums.begin();it != nums.end(); it++)
        {
        auto map_it=m.find(*it);
        if ((map_it)==m.end())
               m[*it]=1;
        else
        return true;
        }
        return false;


    }
};
