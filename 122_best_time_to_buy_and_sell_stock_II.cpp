class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        int max=0;
        int prev=prices[0],pos=prices[0];
        for (int i=1;i<prices.size();i++) {
            if (prices[i]>=prices[i-1]) pos=prices[i];
            else {
                max=max+pos-prev;
                pos=prev=prices[i];
                }
        }
        max=max+pos-prev;
        return max;
    }
};
