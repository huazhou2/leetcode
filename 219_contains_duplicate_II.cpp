class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty())
            return false;
        unordered_map<int,int> index_map;
        for (auto it=nums.begin(); it != nums.end();it++){
            auto map_it=index_map.find(*it);
            if (map_it != index_map.end() && it-nums.begin()-map_it->second<=k)
            return true;
            index_map[*it]=it-nums.begin();
        }
        return false;
    }
};
