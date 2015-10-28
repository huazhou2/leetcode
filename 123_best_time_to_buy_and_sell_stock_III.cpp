class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()<2) return 0;
        vector<int> left, right;
        maxProfone(prices, left, right);
        int max=left.back();
        for (int i=0;i<prices.size();i++) {
            int temp=left[i]+right[prices.size()-i-1];
            max=max>temp? max:temp;
        }
        return max;
    }
    void maxProfone(vector<int>& prices, vector<int>& left, vector<int>& right) {
        left.push_back(0);
        right.push_back(0);
        int max=0,max_temp=0;
        int size=prices.size();
        for (int i=1;i<size;i++) {
            int diff=prices[i]-prices[i-1];
            max_temp=max_temp+diff;
            if (diff>=0) max=max>max_temp?max:max_temp;
            else if (max_temp<=0) max_temp=0;
            left.push_back(max);
        }
        max=0,max_temp=0;
        size=prices.size();
       for (int i=1;i<size;i++) {
           int diff=prices[size-i]-prices[size-1-i];
           max_temp=max_temp+diff;
           if (diff>=0) max=max>max_temp?max:max_temp;
           else if (max_temp<=0) max_temp=0;
          right.push_back(max);
       }
    }
};
