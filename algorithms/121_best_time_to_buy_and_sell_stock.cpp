class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0,max_temp=0;
        vector<int> diff;
        for (int i=1;i<prices.size();i++) 
            diff.push_back(prices[i]-prices[i-1]);
        for (int i=0;i<diff.size();i++) {
            max_temp=max_temp+diff[i];
            if (diff[i]>=0) max=max>max_temp?max:max_temp;
            else if (max_temp<=0) max_temp=0;
        }
        return max;
    }
};
