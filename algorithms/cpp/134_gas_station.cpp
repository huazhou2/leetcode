class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;
        int sum=0;
        for (int i=0;i<gas.size();i++) {
            
            diff.push_back(gas[i]-cost[i]);
            sum+=diff.back();
        }
        if (sum<0) return -1;
        else {
            int start=0;
            int sum=0;
            for (int i=0;i<diff.size();i++) {
                sum+=diff[i];
                if (sum<0) {
                    start=i+1;
                    sum=0;
                }
            }
            return start;
                }
    }
};
