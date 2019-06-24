ass Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k>prices.size()/2) return maxProf(prices);
        vector<vector<int> > local (prices.size(),vector<int>(k+1));
        vector<vector<int> > global(local);
        if (prices.size()<2|| k<=0) return 0;
        for (int i=1;i<prices.size();i++) {
            int diff=prices[i]-prices[i-1];
            for (int j=1;j<=k;j++) {
                local[i][j]=max(global[i-1][j-1]+max(diff,0), local[i-1][j]+diff);
                global[i][j]=max(global[i-1][j], local[i][j]);
            }
        }
        return global[prices.size()-1][k];
    }

    int maxProf(vector<int>& prices) {
        int max=0;
        if (prices.size()<2) return 0;
        int pre,pos;
        pre=pos=prices[0];
        for (int i=1;i<prices.size();i++) {
            if (prices[i]<prices[i-1]) 
               { max=max+pos-pre;
                pre=pos=prices[i];}
            else 
                pos=prices[i];
        }
        max=max+pos-pre;
        return max;
    }
};
